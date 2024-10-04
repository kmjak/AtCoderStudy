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


// int main()
// {
//   int n,k;
//   cin >> n >> k;
//   vi h(n+k,0);
//   rep(i,0,n) cin >> h[i];

//   vi dp(n+k,INT_MAX);
//   dp[0] = 0;
//   rep(i,0,n){
//     rep(j,1,k+1){
//       chmin(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
//     }
//   }

//   cout << dp[n-1] << endl;
//   return 0;
// }


// 復習
int main()
{
  int n,k;
  cin >> n >> k;
  vi h(n+k);
  vi dp(n+k,INT_MAX);
  rep(i,0,n) cin >> h[i];
  rep(i,0,k) h[n+i] = h[n-1];
  dp[0] = 0;
  rep(i,0,n){
    rep(j,1,k+1){
      chmin(dp[i+j],dp[i] + abs(h[i] - h[i+j]));
    }
  }

  cout << dp[n] << endl;

  return 0;
}