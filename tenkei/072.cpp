#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toll(s) stoll(s)
#define btoi(b) static_cast<ll>(b.to_ulong())

using namespace std;

using ll=long long int;
using qll=queue<ll>;
using dq=deque<ll>;

using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

/**
 * 考察
 * H*Wが16と限りなく小さいのでdfsを使用して全探索をする
 */

ll H,W;
vs G(16);
ll res=-1;

void dfs(vvll dist, pair<ll,ll> cur, pair<ll,ll> st)
{
  for(ll i=0;i<4;i++){
    ll nx=cur.first+dx[i];
    ll ny=cur.second+dy[i];
    if(!isRange(nx, ny, W, H)) continue;
    if(G[ny][nx]=='#') continue;
    if(dist[ny][nx]>0) continue;
    dist[ny][nx]=dist[cur.second][cur.first]+1;
    if(st.first==nx && st.second==ny){
      chmax(res, dist[st.second][st.first]);
      // cout<<res<<endl;
      continue;
    }
    dfs(dist, {nx, ny}, st);
    dist[ny][nx]=-1;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>H>>W;
  for(ll i=0;i<H;i++)cin>>G[i];
  vvll dist(H, vll(W, -1));
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      if(G[i][j]=='#') continue;
      dist[i][j]=0;
      dfs(dist, {j, i}, {j, i});
      dist[i][j]=-1;
    }
  }
  cout<<(res==2?-1:res)<<endl;
  return 0;
}