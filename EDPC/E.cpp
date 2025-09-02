#include <bits/stdc++.h>

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define vvs vector<vs>
#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define repra(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back

using namespace std;

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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // ll n,w;
  // cin >> n >> w;
  // ll max_v = pow(10,3) * n + 10;
  // vector<pair<ll,ll>> items;
  // rep(i,0,n){
  //   ll W,V;
  //   cin >> W >> V;
  //   items.pb(make_pair(W,V));
  // }

  // vvll dp(n+1, vll(max_v,w+1));
  // dp[0][0] = 0;

  // rep(i,0,n){
  //   rep(j,0,max_v){
  //     chmin(dp[i+1][j],dp[i][j]);
  //     if(j >= items[i].second){
  //       chmin(dp[i+1][j],items[i].first + dp[i][j - items[i].second]);
  //     }
  //   }
  // }

  // ll res = 0;
  // rep(i,0,max_v){
  //   if(dp[n][i] <= w) res = i;
  // }

  // cout << res << endl;

  ll N,W;
  cin >> N >> W;
  ll Max_V = 1000 * N + 10;
  vll w(N),v(N);
  rep(i,0,N){
    cin >> w[i] >> v[i];
  }
  vvll DP(N+1,vll(Max_V,W+1));
  DP[0][0] = 0;
  rep(i,0,N){
    rep(j,0,Max_V){
      chmin(DP[i+1][j],DP[i][j]);
      if(j >= v[i]) chmin(DP[i+1][j],w[i] + DP[i][j - v[i]]);
    }
  }
  ll res = 0;
  rep(i,0LL,Max_V){
    // if(DP[N][i] <= W ) cout << DP[N][i] << " ";
    if(DP[N][i] <= W && res != i) res = i;
  }
  cout << res << endl;
  return 0;
}