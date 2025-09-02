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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s, t;
  cin >> s >> t;

  // DPテーブルの初期化
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

  // LCSの長さを計算
  rep(i, 1, s.size() + 1) {
    rep(j, 1, t.size() + 1) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  repa(x,dp){
    repa(y,x){
      cout << y << " ";
    }
    cout << endl;
  }

  // LCSの復元
  string lcs = "";
  int i = s.size(), j = t.size();
  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      lcs += s[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  reverse(lcs.begin(), lcs.end());
  cout << lcs << endl;

  return 0;
}