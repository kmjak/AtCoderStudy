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

using ll=long long int;
using pi=pair<int,int>;

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

// int H,W;

// vi bfs(vvi &G)
// {
//   queue<int> q;
//   vi dist(H*W,-1);
//   q.push(0);
//   dist[0] = 0;

//   while(!q.empty()){
//     int n = q.front();
//     q.pop();

//     repa(x,G[n]){
//       if(dist[x] == -1){
//         q.push(x);
//         dist[x] = dist[n]+1;
//       }
//     }
//   }
//   return dist;
// }

// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   cin >> H >> W;
//   vvi G(H*W);

//   vector<vc> field(H, vector<char>(W));
//   int unused = 0;
//   rep(i,0,H){
//     string s;
//     cin >> s;
//     rep(j,0,W){
//       field[i][j] = s[j];
//       if(s[j] == '.'){
//         if(j != W-1) G[i*W + (j+1)].pb(i * W + j);
//         if(j != 0) G[i*W + (j-1)].pb(i * W + j);
//         if(i != H-1) G[(i+1)*W + j].pb(i * W + j);
//         if(i != 0) G[(i-1)*W + j].pb(i * W + j);
//       } else {
//         unused++;
//       }
//     }
//   }

//   if (field[H-1][W-1] == '#') {
//     cout << -1 << endl;
//     return 0;
//   }

//   vi dist = bfs(G);
//   if(dist[H*W-1] == -1){
//     cout << -1 << endl;
//   } else {
//     cout << H * W - unused - dist[H*W-1] - 1 << endl;
//   }
//   return 0;
// }

vi DX = {1, 0, -1, 0};
vi DY = {0, 1, 0, -1};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int H,W;
  cin >> H >> W;
  vs S(H);
  rep(i,0,H) cin >> S[i];
  queue<pi> que;
  vvi dist(H,vi(W,-1));
  que.push(mp(0,0));
  dist[0][0] = 0;
  while(!que.empty()){
    pi tmp = que.front();
    que.pop();
    int x = tmp.first;
    int y = tmp.second;

    rep(i,0,4){
      int nx = x + DX[i];
      int ny = y + DY[i];

      if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
      if(S[nx][ny] == '#') continue;
      if(dist[nx][ny] != -1) continue;

      que.push(mp(nx,ny));
      dist[nx][ny] = dist[x][y] + 1;
    }
  }
  int white = 0;
  rep(i,0,H){
    white += count(all(S[i]),'.');
  }

  int res = -1;
  if(dist[H-1][W-1] != -1){
    res = white - (dist[H-1][W-1] + 1);
  }

  cout << res << endl;
}