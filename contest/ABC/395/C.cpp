#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

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

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(A) rep(i,0,A.size()) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ')

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
  vi idx;

  bool operator<(const pnt &p) const {
    return idx.size() > p.idx.size();
  }
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin>>N;
  vi A(N);
  map<int,vi> m;
  rep(i,0,N) {
    cin>>A[i];
    m[A[i]].eb(i+1);
  }
  if(m.size()==N){
    cout<<-1<<endl;
    return 0;
  }

  vector<pair<int,vi>> v;
  repa(x,m){
    v.eb(mp(x.first,x.second));
  }

  sort(all(v),[](pair<int,vi> a,pair<int,vi> b){
    return a.second.size()>b.second.size();
  });

  int res=-1;
  repa(x,v){
    if(x.second.size()==1)break;
    int diff=x.second[1]-x.second[0];
    rep(i,1,x.second.size()-1){
      chmin(diff,x.second[i+1]-x.second[i]);
    }
    if(res==-1)res=diff;
    else chmin(res,diff);
  }
  cout<<res+1<<endl;
  return 0;
}