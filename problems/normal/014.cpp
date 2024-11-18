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

using namespace std;

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

vi DX = {1,0,-1,0};
vi DY = {0,1,0,-1};
int H,W;

bool isRange(int nx, int ny)
{
  if(nx < W && ny < H && min(nx,ny) > -1){
    return true;
  }
  return false;
}

bool bfs(vs &Grid,pi start)
{
  queue<pi> q;
  q.push(start);
  vvi dist(H,vi(W,-1));
  dist[start.first][start.second] = 0;
  bool check = false;
  while(!q.empty()){
    pi current = q.front();
    q.pop();
    rep(i,0,4) {
      ll nx = current.second + DX[i];
      ll ny = current.first + DY[i];
      if(isRange(nx,ny)){
        if(dist[ny][nx] == -1 && Grid[ny][nx] == '#'){
          q.push(mp(ny,nx));
          dist[ny][nx] = dist[current.first][current.second] + 1;
          check = true;
        }
      }
    }
  }
  return check;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> H >> W;
  vs Grid(H);
  vcin(H,Grid);
  rep(i,0,H) {
    rep(j,0,W) {
      if(Grid[i][j] == '#'){
        if(!bfs(Grid,mp(i,j))){
          NO;
          return 0;
        }
      }
    }
  }
  YES;
  return 0;
}