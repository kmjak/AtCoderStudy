#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toll(s) stoll(s)
#define btoi(b) static_cast<ll>(b.to_ulong())

using namespace std;

using ll=long long int;
using qll=queue<ll>;
using dq=deque<ll>;

using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

/**
 * 考察
 */
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,Q;
  cin>>N>>Q;
  vll A(N);
  for(ll i=0;i<N;i++)cin>>A[i];

  vvll dp(40,vll(N+10));
  for(ll i=1;i<=N;i++)dp[0][i]=A[i-1];
  for(ll i=1;i<=29;i++){
    for(ll j=1;j<=N;j++){
      dp[i][j]=dp[i-1][dp[i-1][j]];
    }
  }

  while(Q--){
    ll x,y;cin>>x>>y;

    for(ll i=29;i>=0;i--){
      if((y/(1<<i))%2!=0)x=dp[i][x];
    }
    cout<<x<<endl;
  }

  // for(ll i=0;i<40;i++){
  //   for(ll j=0;j<N;j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  return 0;
}