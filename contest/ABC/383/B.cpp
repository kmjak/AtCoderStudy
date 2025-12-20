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

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define END cout << '\n'

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int H, W, D;
    cin >> H >> W >> D;
    vs field(H);
    vcin(H, field);
    vector<pi> pattern;
    rep(i, 0, H) {
      rep(j, 0, W) {
        if (field[i][j] == '.') {
          pattern.pb({i, j});
        }
      }
    }
    int res = 0;
    int n = pattern.size();
    rep(i, 0, n) {
      rep(j, i, n) {
        vector<pi> A = {pattern[i]};
        if (i != j) A.pb(pattern[j]);
        set<pi> s;
        repa(h, A) {
          s.insert(h);
        }
        repa(p, pattern) {
          bool f = false;
          repa(h, A) {
            int dist = abs(p.first - h.first) + abs(p.second - h.second);
            if (dist <= D) {
              f = true;
              break;
            }
          }
          if (f) {
            s.insert(p);
          }
        }
        chmax(res, (int)s.size());
      }
    }
    cout << res << endl;
    return 0;
}