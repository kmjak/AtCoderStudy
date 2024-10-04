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

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<char>> c(h, vector<char>(w));
  vvi f(h, vi(w, 0));

  rep(i, 0, h) {
    rep(j, 0, w) {
      cin >> c[i][j];
      if (c[i][j] == '#') {
        rep(k, -1, 2) {
          rep(l, -1, 2) {
            int ni = i + k, nj = j + l;
            if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
              f[ni][nj]++;
            }
          }
        }
      }
    }
  }

  rep(i, 0, h) {
    rep(j, 0, w) {
      if (c[i][j] == '#')
        cout << '#';
      else
        cout << f[i][j];
    }
    cout << endl;
  }

  return 0;
}