#include <bits/stdc++.h>

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
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

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

vs G(1010);
int H,W;
queue<pi> start;

vi dx={1,0,-1,0};
vi dy={0,1,0,-1};
vc chr={'<','^','>','v'};

bool isRange(int x,int y)
{
  return 0<=x&&x<W&&0<=y&&y<H;
}

void bfs()
{
  vvi dist(H,vi(W,-1));
  queue<pi> q;
  while(!start.empty()){
    pi st=start.front();
    start.pop();
    q.push(st);
    dist[st.second][st.first]=0;
  }

  while(!q.empty()){
    pi p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;

    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!isRange(nx,ny))continue;
      if(G[ny][nx] == '#')continue;
      if(G[ny][nx] == 'E')continue;
      if(dist[ny][nx] != -1)continue;
      dist[ny][nx]=dist[y][x]+1;
      G[ny][nx]=chr[i];
      q.push(mp(nx,ny));
    }
  }

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>H>>W;

  for(int i=0;i<H;i++){
    cin>>G[i];
    for(int j=0;j<W;j++){
      if(G[i][j] == 'E'){
        start.push(mp(j,i));
      }
    }
  }

  bfs();

  for(int i=0;i<H;i++){
    cout<<G[i]<<endl;
  }
  return 0;
}
