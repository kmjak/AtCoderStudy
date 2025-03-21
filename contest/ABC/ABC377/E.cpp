#include <bits/stdc++.h>

#define rep(i, s, n) for (auto i = s; i < n; i++)
#define rrep(i, s, n) for (auto i = s; i > n; i--)
#define repa(i, x) for (auto i : x)
#define rrepa(i, x) for (auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define g(i, t) get<i>(t)

#define tos(n) to_string(n)
#define toi(s) stoi(s)

#define NO cout << "No" << endl;
#define YES cout << "Yes" << endl;

#define vcin(N, A) rep(i, 0, N) cin >> A[i];
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

using namespace std;

using ll = long long int;
using pi = pair<int, int>;
using qi = queue<int>;

using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;

using vvi = vector<vi>;
using vvll = vector<vll>;

template <typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T> inline bool chmax(T &a, T b) {
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

  long long unsigned N, K;
  cin >> N >> K;
  vi P(N);
  vcin(N, P);

  vi init = P;
  ll c = 0;
  vector<vector<int>> res;

  while (K--) {
    vi tmp(N);
    rep(i, 0, N) {
      tmp[i] = P[P[i] - 1];
    }
    res.pb(P);
    P = tmp;

    c++;
    if (P == init) {
      vcout(res[K % c]);
      return 0;
    }
  }
  vcout(P);

  return 0;
}
