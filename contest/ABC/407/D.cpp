#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

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
};

vi dx = {1, 0};
vi dy = {0, 1};

int H,W;
vvll G(20);
long long res = 0;

bool isRange(int x, int y)
{
  return 0<=x&&x<W && 0<=y&&y<H;
}

void dfs(vector<vb> &vis, int cur)
{
  int curX = cur % W;
  int curY = cur / W;
  if(cur == H * W) {
    ll score = 0;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++){
      if(vis[i][j]) continue;
      score ^= G[i][j];
    }
    chmax(res, score);
    return;
  }
  cur++;

  if(vis[curY][curX]) {
    dfs(vis, cur);
    return;
  }

  dfs(vis, cur);

  for(int i = 0; i<2; i++) {
    int nx = curX + dx[i];
    int ny = curY + dy[i];

    if(!isRange(nx, ny)) continue;
    if(vis[ny][nx]) continue;
    vis[curY][curX] = true;
    vis[ny][nx] = true;
    dfs(vis, cur);
    vis[curY][curX] = false;
    vis[ny][nx] = false;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> H >> W;
  for(int i = 0;i<H;i++){
    for(int j=0;j<W;j++){
      ll x;
      cin >> x;
      G[i].eb(x);
    }
  }

  vector<vb> vis(H, vb(W, false));

  dfs(vis, 0);
  cout << res << endl;
  return 0;
}