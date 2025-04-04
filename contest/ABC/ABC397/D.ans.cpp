#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(A) rep(i,0,A.size()) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ')

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

using namespace std;

using ll = long long;  // ← 修正
using pi = pair<int, int>;
using qi = queue<int>;
using qp = queue<pi>;
using si = set<int>;

using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;

using vvi = vector<vi>;
using vvll = vector<vll>;

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

ll solve(ll a, ll b, ll c) {
  ll l = 0, r = 600000001;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (a * mid * mid + b * mid + c <= 0) l = mid;
    else r = mid;
  }
  if (a * l * l + b * l + c == 0) return l;
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll X;
  cin >> X;

  for (ll d = 1; d * d * d <= X; ++d) {
    if (X % d != 0) continue;
    ll m = X / d;
    ll k = solve(3, 3 * d, d * d - m);
    if (k > 0) {
      cout << k + d << " " << k << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}