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


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vi k(n);
  rep(i, 0, n) cin >> k[i];

  int total = accumulate(k.begin(), k.end(), 0);
  int minDiff = INT_MAX;
  int maxSum = 0;

  rep(mask, 0, (1 << n)) {
    int sumA = 0;
    int sumB = 0;

    rep(i, 0, n) {
      if (mask & (1 << i)) {
        sumB += k[i];
      } else {
        sumA += k[i];
      }
    }

    int diff = abs(sumA - sumB);
    if (diff < minDiff) {
      minDiff = diff;
      maxSum = max(sumA, sumB);
    } else if (diff == minDiff) {
      maxSum = max(maxSum, max(sumA, sumB));
    }
  }

  cout << maxSum << endl;
  return 0;
}