#include <bits/stdc++.h>
using namespace std;

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
#define toi(s) stoi(s)

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;

using vvi=vector<vi>;
using vvll=vector<vll>;

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

long double dist(int x, int y, int nx, int ny) {
  return sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vector<pi> position(N);
  vi p(N);
  rep(i, 0, N) {
    cin >> position[i].first >> position[i].second;
    p[i] = i;
  }

  long double res = 0;
  int c = 0;
  do {
    rep(i, 0, N - 1) {
      res += dist(position[p[i]].first, position[p[i]].second, position[p[i+1]].first, position[p[i+1]].second);
    }
    c++;
  } while (next_permutation(all(p)));

  cout << fixed << setprecision(6) << res / c << '\n';
  return 0;
}