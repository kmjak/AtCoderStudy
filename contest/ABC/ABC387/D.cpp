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

struct pnt {
  ll x;
  ll y;
  char prev_action;
};

ll H,W;
vi dx = {1,0,-1,0};
vi dy = {0,1,0,-1};

int bfs(vs &field, int sx, int sy)
{
  queue<pnt> que;
  vvi dist(H, vi(W, -1));
  que.push(pnt{sx, sy, 'S'});
  dist[sx][sy] = 0;
  while(!que.empty()) {
    pnt p = que.front();
    que.pop();
    rep(i,0,4) {
      if(p.prev_action == 'X' && i % 2 == 0) {
        continue;
      }
      if(p.prev_action == 'Y' && i % 2 == 1) {
        continue;
      }
      int nx = p.x + dx[i];
      int ny = p.y + dy[i];
      if(nx < 0 || nx >= H || ny < 0 || ny >= W) {
        continue;
      }
      if(field[nx][ny] == 'G') {
        return dist[p.x][p.y] + 1;
      }
      if(field[nx][ny] == '#') {
        continue;
      }
      if(dist[nx][ny] != -1) {
        continue;
      }
      rep(j,0,4) {
        if(i % 2 == j % 2) {
          continue;
        }
        int nnx = nx + dx[j];
        int nny = ny + dy[j];
        if(nnx < 0 || nnx >= H || nny < 0 || nny >= W) {
          continue;
        }
        if(field[nnx][nny] == 'G') {
          return dist[p.x][p.y] + 1;
        }
        if(field[nnx][nny] == '#') {
          continue;
        }
        if(dist[nnx][nny] != -1) {
          continue;
        }
        dist[nnx][nny] = dist[p.x][p.y] + 2;
        if(i % 2 == 0){
          que.push(pnt{nx, ny, 'X'});
        }else{
          que.push(pnt{nx, ny, 'Y'});
        }
      }
    }
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> H >> W;
  vs S(H);
  vcin(H,S);
  rep(i,0,H) {
    rep(j,0,W) {
      if(S[i][j] == 'S') {
        cout << bfs(S, i, j) << '\n';
        return 0;
      }
    }
  }
  return 0;
}