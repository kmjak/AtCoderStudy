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
  ll N,H,M;
  cin>>N>>H>>M;

  vvll dp(3010, vll(3010, -1));
  dp[0][H] = M;

  int res=0;

  for(ll i=0;i<N;i++) {
    ll h,m;
    bool ok = false;
    cin>>h>>m;
    for(ll j=0;j<=H;j++){
      if (dp[i][j] == -1) continue;
      if(j-h >= 0) {
        chmax(dp[i+1][j-h], dp[i][j]);
        ok = true;
      }

      if(dp[i][j] - m >= 0){
        chmax(dp[i+1][j], dp[i][j] - m);
        ok = true;
      }
    }
    if(ok == false)continue;
    res++;
  }

  // for(ll i=0;i<=N;i++){
  //   for(ll j=0;j<=H;j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  cout<<res<<endl;
  return 0;
}
