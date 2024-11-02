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
#define toi(s) stoi(s)

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

#define sort(x) sort(all(x))
#define rsort(x) sort(rall(x))

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;

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

int H,W,K;

vi dx = {1, 0, -1, 0};
vi dy = {0, 1, 0, -1};

// int bfs(int x, int y ,vs S)
// {
//   vvi dist(H, vi(W, -1));
//   queue<pi> q;
//   q.push(mp(x, y));
//   dist[x][y] = 0;
//   while (!q.empty()) {
//     pi p = q.front();
//     q.pop();
//     int x = p.first;
//     int y = p.second;
//     rep(i, 0, 4) {
//       int nx = x + dx[i];
//       int ny = y + dy[i];
//       if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
//       if (dist[nx][ny] != -1) continue;
//       if (S[nx][ny] == '#') continue;
//       if (dist[x][y] == K) {
//         dist[nx][ny] = K;
//       } else {
//         dist[nx][ny] = dist[x][y] + 1;
//       }
//       q.push(mp(nx, ny));
//     }
//   }
//   int c = 0;
//   rep(i, 0, H) {
//     c += count(all(dist[i]), K);
//   }
//   return c;
// }
// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   cin >> H >> W >> K;
//   vs S(H);
//   vcin(H, S);
//   rep(i,0,H) {
//     rep(j,0,W) {
//       if(S[i][j] == '#') continue;
//       cnt += bfs(i, j, S);
//     }
//   }
//   cout << cnt << '\n';
//   return 0;
// }


// int bfs(int x, int y ,vs S)
// {
//   vector<vector<pi>> dist(H, vector<pi> (W, mp(-1, -1)));
//   queue<pi> q;
//   q.push(mp(x, y));
//   dist[x][y] = mp(0, 1);
//   while (!q.empty()) {
//     pi p = q.front();
//     q.pop();
//     int x = p.first;
//     int y = p.second;
//     rep(i, 0, 4) {
//       int nx = x + dx[i];
//       int ny = y + dy[i];
//       if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
//       if (dist[nx][ny].first != -1){
//         dist[nx][ny].second += dist[x][y].second;
//         continue;
//       }
//       if (S[nx][ny] == '#') continue;
//       if (dist[x][y].first == K) {
//         dist[nx][ny] = dist[x][y];
//       } else {
//         dist[nx][ny] = dist[x][y];
//         dist[nx][ny].first++;
//       }
//       q.push(mp(nx, ny));
//     }
//   }
//   int c = 0;
//   rep(i, 0, H) {
//     rep(j, 0, W) {
//       if(dist[i][j].first == K) c += dist[i][j].second;
//     }
//   }
//   return c;
// }
// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   cin >> H >> W >> K;
//   vs S(H);
//   vcin(H, S);
//   rep(i,0,H) {
//     rep(j,0,W) {
//       if(S[i][j] == '#') continue;
//       cnt += bfs(i, j, S);
//     }
//   }
//   cout << cnt << '\n';
//   return 0;
// }

// int bfs(int x, int y ,vs S)
// {
//   vector<vector<tuple<int,int,int,int>>> dist(H, vector<tuple<int,int,int,int>> (W, mt(-1, -1,0,0)));
//   queue<pi> q;
//   q.push(mp(x, y));
//   dist[x][y] = mt(0, 1,-1,-1);
//   while (!q.empty()) {
//     pi p = q.front();
//     q.pop();
//     int x = p.first;
//     int y = p.second;
//     rep(i, 0, 4) {
//       int nx = x + dx[i];
//       int ny = y + dy[i];
//       if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
//       if (S[nx][ny] == '#') continue;
//       if (get<0>(dist[nx][ny]) != -1){
//         queue<pi> tmp;
//         int npf = g(2,dist[nx][ny]);
//         int nps = g(3,dist[nx][ny]);
//         if(npf == -1 || nps == -1) {
//         g(1,dist[ny][nx]) += g(1,dist[x][y]);
//           continue;
//         }
//         int prevf = npf;
//         int prevs = nps;
//         tmp.push(mp(g(2,dist[nx][ny]),g(3,dist[nx][ny])));
//         while(!tmp.empty()) {
//           pi p2 = tmp.front();
//           tmp.pop();
//           if(p2.first == -1 || p2.second == -1) break;
//           npf = g(2,dist[p2.first][p2.second]);
//           nps = g(3,dist[p2.first][p2.second]);
//           if(npf == -1 || nps == -1) break;
//           prevf = npf;
//           prevs = nps;
//           tmp.push(mp(npf,nps));
//         }
//         g(1,dist[prevf][prevs]) += g(1,dist[x][y]);
//         cout << prevf << " " << prevs << " : " << x << " " << y << '\n';
//         continue;
//       }
//       if (g(0,dist[x][y]) == K) {
//         dist[nx][ny] = dist[x][y];
//       } else {
//         dist[nx][ny] = dist[x][y];
//         g(0,dist[nx][ny])++;
//       }
//       g(2,dist[x][y]) = nx;
//       g(3,dist[x][y]) = ny;
//       q.push(mp(nx, ny));
//     }
//   }
//   int c = 0;
//   rep(i, 0, H) {
//     rep(j, 0, W) {
//       if(std::get<0>(dist[i][j]) == K) c += std::get<1>(dist[i][j]);
//     }
//   }
//   return c;
// }
// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   cin >> H >> W >> K;
//   vs S(H);
//   vcin(H, S);
//   rep(i,0,H) {
//     rep(j,0,W) {
//       if(S[i][j] == '#') continue;
//       cnt += bfs(i, j, S);
//     }
//   }
//   cout << cnt << '\n';
//   return 0;
// }


ll res = 0;

void bfs(int y, int x, int k, vs S, vector<vector<bool>>& V)
{
  if(K==k){
    res++;
    return;
  }
  V[y][x] = true;
  rep(i,0,4) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
    if(S[ny][nx] == '#') continue;
    if(V[ny][nx]) continue;
    bfs(ny, nx, k+1, S, V);
  }
  V[y][x] = false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> H >> W >> K;
  vs S(H);
  vcin(H, S);
  vector<vector<bool>> V(H, vector<bool>(W, false));

  rep(i,0,H) {
    rep(j,0,W) {
      if(S[i][j] == '.'){
        bfs(i, j, 0, S, V);
      }
    }
  }
  cout << res << '\n';
}