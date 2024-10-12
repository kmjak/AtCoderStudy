#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

using ll = long long int;
using pi = pair<int, int>;

using vi = vector<int>;
using vll = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;

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

double dist(pi a, pi b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  pi current = mp(0, 0);
  double costs = 0;
  rep(i, 0, N) {
    int x, y;
    cin >> x >> y;
    costs += dist(current, mp(x, y));
    current = mp(x, y);
  }
  costs += dist(current, mp(0, 0));

  cout << defaultfloat << setprecision(numeric_limits<double>::max_digits10) << costs << endl;
  return 0;
}