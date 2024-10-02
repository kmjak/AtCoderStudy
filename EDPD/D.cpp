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

  int n,w;
  cin >> n >> w;
  vector<pair<ll,ll>> item;
  item.pb(make_pair(0,0));
  rep(i,0,n){
    ll x,y;
    cin >> x >> y;
    item.pb(make_pair(x,y));
  }

  vvll dp(n+1,vll(w+1,0));

  rep(i,1,n+1){
    rep(j,0,w+1){
      dp[i][j] = dp[i-1][j];
      if(j >= item[i].first){
        chmax(dp[i][j],dp[i-1][j-item[i].first] + item[i].second);
      }
    }
  }

  ll res = 0;
  rep(i,1,w+1){
    chmax(res, dp[n][i]);
  }
  cout << res << endl;
  return 0;
}