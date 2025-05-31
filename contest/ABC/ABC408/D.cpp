#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin>>T;
  vi res(T);

  for(int i=0;i<T;i++){
    int N;
    string S;
    cin>>N>>S;
    S+='0';
    int maxLen=0;
    int curLen=0;
    int cnt1=count(all(S),'1');
    int l=-1;
    int r=0;
    for(int j=0;j<=N;j++){
      if(S[j]=='1'){
        if(l==-1) l=j;
        r=j;
        curLen++;
      }else{
        chmax(maxLen,curLen);
        curLen=0;
      }
    }
    res[i]=min(cnt1-maxLen, (int)count(S.begin()+l, S.begin()+r+1, '0'));

  }

  for(int i=0;i<T;i++){
    cout<<res[i]<<endl;
  }
  return 0;
}