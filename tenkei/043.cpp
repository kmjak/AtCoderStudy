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
ll H,W;
vs G(1010);
pair<ll,ll> st,gl;

/**
 * 考察
 * ダイクストラ法で向きが変わるときにscoreを+1して、最小の値でゴールできた数を出力する
 * BFSでも解けそう
 */
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>H>>W;
  cin>>st.first>>st.second;
  cin>>gl.first>>gl.second;
  st.first--; st.second--;
  gl.first--; gl.second--;
  for(ll i=0;i<H;i++)cin>>G[i];

  priority_queue<tuple<ll,ll,ll,ll>, vector<tuple<ll,ll,ll,ll>>, greater<tuple<ll,ll,ll,ll>>> pq;
  pq.push(mt(0, st.first, st.second, -1));
  vvll dist(H, vll(W, LLONG_MAX));
  dist[st.first][st.second] = 0;
  while(!pq.empty()){
    auto [score, y, x, dir] = pq.top();
    pq.pop();

    for(ll i=0;i<4;i++){
      ll sc=score;
      ll ny=y+dy[i];
      ll nx=x+dx[i];
      if(!isRange(nx, ny, W, H)) continue;
      if(G[ny][nx] == '#') continue;
      if(dir!=-1&&dir!=i)sc++;
      if(sc>dist[ny][nx]) continue;
      chmin(dist[ny][nx],sc);
      pq.push(mt(sc, ny, nx, i));
    }
  }
  cout<<dist[gl.first][gl.second]<<endl;
  // for(ll i=0;i<H;i++){
  //   for(ll j=0;j<W;j++){
  //     if(dist[i][j] == LLONG_MAX) cout<<"#";
  //     else cout<<dist[i][j];
  //   }
  //   cout<<endl;
  // }
  return 0;
}