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

int DPs(vi &h, int n)
{
  vi dp(n+1, INT_MAX);
  dp[0] = 0;
  dp[n] = 0;

  int i = 0;
  rep(i, 0, n - 1) {
    chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }

  return dp[n - 1];
}
int main()
{
  int n;
  cin >> n;
  vi h(n);
  rep(i, 0, n) cin >> h[i];
  cout << DPs(h, n) << endl;
  return 0;
}