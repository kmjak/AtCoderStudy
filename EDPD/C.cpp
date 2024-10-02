#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>

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
  int n;
  cin >> n;
  vvi dp(n+1, vi(3, INT_MIN));

  rep(i,0,3){
    dp[0][i] = 0;
  }

  rep(i,0,n){
    vi d(3);
    cin >> d[0] >> d[1] >> d[2];
    rep(j,0,3){
      rep(k,0,3){
        if(j != k) chmax(dp[i+1][j], dp[i][k] + d[k]);
      }
    }
  }

  int res = 0;
  rep(i,0,3) chmax(res,dp[n][i]);

  cout << res << endl;
  return 0;
}