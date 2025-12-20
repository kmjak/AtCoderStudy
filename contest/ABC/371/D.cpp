#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define rep(i, s, n) for(auto i = s; i < n; i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> p(n);

  rep(i, 0, n) cin >> x[i];
  rep(i, 0, n) cin >> p[i];

  vector<pair<int, int>> v;
  rep(i, 0, n) v.emplace_back(x[i], p[i]);

  sort(v.begin(), v.end());

  vector<long long> prefix_sum(n);
  prefix_sum[0] = v[0].second;
  rep(i, 1, n) {
    prefix_sum[i] = prefix_sum[i - 1] + v[i].second;
  }

  int q;
  cin >> q;
  vector<long long> results(q);

  rep(i, 0, q) {
    int l, r;
    cin >> l >> r;

    auto it_l = lower_bound(v.begin(), v.end(), make_pair(l, 0));
    auto it_r = upper_bound(v.begin(), v.end(), make_pair(r, INT_MAX));

    int idx_l = std::distance(v.begin(), it_l);
    int idx_r = std::distance(v.begin(), it_r) - 1;

    long long result = 0;
    if (idx_l <= idx_r && idx_l < n) {
      result = prefix_sum[idx_r];
      if (idx_l > 0) {
        result -= prefix_sum[idx_l - 1];
      }
    }

    results[i] = result;
  }

  rep(i, 0, q) {
    cout << results[i] << endl;
  }

  return 0;
}