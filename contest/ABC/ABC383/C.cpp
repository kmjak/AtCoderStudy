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

ll H, W, D;
vi dx = {1, 0, -1, 0};
vi dy = {0, 1, 0, -1};
set<pi> res;

bool isRange(int x, int y)
{
  return 0 <= x && x < H && 0 <= y && y < W;
}

bool isManhattan(int x1, int y1, int x2, int y2)
{
  return abs(x1 - x2) + abs(y1 - y2) <= D;
}

int bfs(vs &field, vvll &V , int x, int y,int k)
{
  qp q;
  q.push(mp(x, y));
  res.insert(mp(x, y));
  V[x][y] = true;
  while(!q.empty()) {
    pi p = q.front();
    q.pop();
    rep(i,0,4) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];
      if(!isRange(nx, ny)) continue;
      if(field[nx][ny] == '#') continue;
      if(V[nx][ny] == k) continue;
      if(!isManhattan(x, y, nx, ny)) continue;
      V[nx][ny] = k;
      q.push(mp(nx, ny));
      res.insert(mp(nx, ny));
    }
  }
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> H >> W >> D;
  vs field(H);
  vcin(H, field);
  vvll V(H, vll(W, -1));
  int k = 0;
  rep(i,0,H) {
    rep(j,0,W) {
      if(field[i][j] == 'H'){
        bfs(field, V, i, j, k);
        k++;
      }
    }
  }
  cout << res.size() << '\n';
  return 0;
}