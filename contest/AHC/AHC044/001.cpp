#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

using vvi=vector<vi>;
using vvll=vector<vll>;

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

struct pnt {
  ll x;
  ll y;
};

// N=100, L=5e5固定
int N,L;
vector<pi> res(100);
vector<long double> T(100);
map<int,int> useCnt;

pair<ll,vi> getScore(vector<pi> tg) {
  ll score = 0;
  vi cnt(N,0);
  int now=0;
  for(int i=0;i<5e5;i++){
    auto [odd,even]=tg[now];
    if(cnt[now]%2==0)now=odd;
    else now=even;
    cnt[now]++;
  }
  vi diff(N);
  for(int i=0;i<N;i++){
    diff[i]=T[i]-cnt[i];
    score+=abs(diff[i]);
  }
  return make_pair(score,diff);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>L;
  for(int i=0;i<100;i++)cin>>T[i];
  vector<pi> sortedT(100);
  for(int i=0;i<100;i++)sortedT[i]={T[i],i};
  sort(all(sortedT),greater<pi>());
  int prev=-1;
  for(int i=0;i<100;i++){
    if(i==0)res[i].first=sortedT[i].second;
    else res[i].first=prev;
    res[i].second=sortedT[(i+1)%100].second;
    prev=sortedT[i].second;
  }

  auto [currentMinDiff,diff]=getScore(res);
  // cout<<currentMinDiff<<endl;
  // for(int i=0;i<100;i++)cout<<res[i].first<<" "<<res[i].second<<endl;
  for(int i=0;i<1000;i++){
    vector<pi> lower;
    vector<pi> upper;
    vector<pi> newRes=res;
    for(int j=0;j<100;j++){
      if(diff[j]<0)lower.eb(make_pair(diff[j],j));
      else if(diff[j]>0)upper.eb(make_pair(diff[j],j));
    }
    sort(all(lower));
    sort(rall(upper));
    int l_size=lower.size();
    int u_size=upper.size();
    for(int j=0;j<min(l_size,u_size);j++){
      int k=0;
      while(k<100&&(newRes[k].first!=upper[j].second&&newRes[k].second!=upper[j].second))k++;
      if(k==100)continue;
      if(newRes[k].first==upper[j].second)newRes[k].first=lower[j].second;
      else newRes[k].second=lower[j].second;
    }
    auto [scoreNml,xD]=getScore(newRes);
    // cout<<score<<endl;
    if(scoreNml<currentMinDiff){
      currentMinDiff=scoreNml;
      res=newRes;
    }
  }
  for(int i=0;i<100;i++)cout<<res[i].first<<" "<<res[i].second<<endl;
  return 0;
}