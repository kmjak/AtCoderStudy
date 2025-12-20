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

class SegmentTreeRMQ {
  public:
  vll data;
  ll size = 1;

  void init(ll n){
    while(size < n) size *= 2;
    data.assign(size * 2, 0);
  }

  void update(ll pos, ll x){
    pos += size - 1;
    data[pos] = x;
    while(pos >= 2){
      pos /= 2;
      data[pos] = max(data[pos*2], data[pos*2+1]);
    }
  }

  ll query(ll l, ll r, ll bl, ll br, ll u){
    if(r <= bl || br <= l)return -1e18;
    if(l <= bl && br <= r)return data[u];
    ll m = (bl + br) / 2;
    ll al = query(l, r, bl, m, u*2);
    ll ar= query(l, r, m, br, u*2+1);
    return max(al, ar);
  }
};

class SegmentTreeRSQ {
  public:
  vll data;
  ll size = 1;

  void init(ll n){
    while(size < n) size *= 2;
    data.assign(size * 2, 0);
  }

  void update(ll pos, ll x){
    pos += size - 1;
    data[pos] = x;
    while(pos >= 2){
      pos /= 2;
      data[pos] = data[pos*2] + data[pos*2+1];
    }
  }

  ll query(ll l, ll r, ll bl, ll br, ll u){
    if(r <= bl || br <= l)return 0;
    if(l <= bl && br <= r)return data[u];
    ll m = (bl + br) / 2;
    ll al = query(l, r, bl, m, u*2);
    ll ar= query(l, r, m, br, u*2+1);
    return al + ar;
  }
};

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

/**
 * 考察
 * dfs+G[i]の中を昇順ソートで解く
 *
 * dfsは再帰で実装されるため、G[i]の中を昇順ソートしておくことで、
 * 先に小さいノードを訪問することができる
 * そして、一番最初にゴールに到達したとき、それが辞書順に並べた時の最小のパスになる
 *
 */

vll res;
void dfs(vvll &G, ll cur, vb &vis, ll tg, vll &r){
  vis[cur] = true;
  if(cur == tg){
    res = r;
    return;
  }
  for(auto &nx : G[cur]){
    if(vis[nx]) continue;
    r.eb(nx);
    dfs(G, nx, vis, tg, r);
    r.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll T;cin>>T;
  while(T--){
    ll n,m,x,y;cin>>n>>m>>x>>y;
    x--;y--;
    vvll G(n);
    for(ll i=0;i<m;i++){
      ll u,v;cin>>u>>v;
      u--;v--;
      G[u].eb(v);
      G[v].eb(u);
    }
    vb vis(n, false);
    res.clear();
    vll r={x};
    for(ll i=0;i<n;i++)sort(all(G[i]));
    dfs(G, x, vis, y, r);
    for(ll i=0;i<res.size();i++){
      cout << res[i]+1<<" ";
    }
    cout<<endl;
  }
  return 0;
}