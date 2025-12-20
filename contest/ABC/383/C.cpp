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

ll H,W,D;
vs G(1010);
vi dx={-1,0,1,0};
vi dy={0,-1,0,1};
ll res=0;

bool isRange(ll x, ll y){
  return 0<=x&&x<W&&0<=y&&y<H;
}

void bfs()
{
  queue<pair<ll,ll>> q;
  vvll dist(H, vll(W, -1));
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      if(G[i][j]=='H') {
        dist[i][j] = 0;
        q.push({i,j});
      }
    }
  }
  while(!q.empty()){
    auto [y,x] = q.front();
    q.pop();
    for(ll i=0;i<4;i++){
      ll ny = y + dy[i];
      ll nx = x + dx[i];
      if(!isRange(nx, ny)) continue;
      if(G[ny][nx]=='#') continue;
      if(dist[ny][nx] != -1) continue;
      dist[ny][nx] = dist[y][x] + 1;
      q.push({ny,nx});
    }
  }
  for(ll i=0;i<H;i++)for(ll j=0;j<W;j++) res+= (dist[i][j]!=-1&&dist[i][j]<=D);
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>H>>W>>D;
  for(ll i=0;i<H;i++)cin>>G[i];
  bfs();
  cout<<res<<endl;
  return 0;
}