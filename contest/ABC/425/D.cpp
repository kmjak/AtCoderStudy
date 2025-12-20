#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
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

class UnionFind {
public:
  vll parent, size;

  UnionFind(ll n) : parent(n, -1), size(n, 1) {}

  ll find(ll x) {
    if (parent[x] == -1) return x;
    return parent[x] = find(parent[x]);
  }

  bool unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    return true;
  }

  bool same(ll a, ll b) {
    return find(a) == find(b);
  }

  ll getSize(ll x) {
    return size[find(x)];
  }
};

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

/**
 * 考察
 * 多始点BFSで解けばいい
 * ただ注意点として、同じターンで塗ったマスは隣接してもいいので
 * distでターンを管理して、塗られているかつdistが小さいマスの数を数えて
 * 2以上なら塗らないようにする
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll mod=1e9+7;
const ll inf=1e18;

vs G(3e5+10);
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll H,W;cin>>H>>W;
  queue<pair<ll,ll>> q;
  vvll dist(H,vll(W,-1));
  ll res=0;
  for(ll i=0;i<H;i++){
    cin>>G[i];
    for(ll j=0;j<W;j++){
      if(G[i][j]=='#'){
        q.push({j,i});
        dist[i][j]=0;
        res++;
      }
    }
  }

  while(!q.empty()){
    auto [x,y]=q.front();q.pop();
    for(ll i=0;i<4;i++){
      ll nx=x+dx[i], ny=y+dy[i];
      if(!isRange(nx,ny,W,H))continue;
      if(dist[ny][nx]!=-1)continue;
      ll score=dist[y][x]+1;
      ll cnt=0;
      for(ll j=0;j<4;j++){
        ll nnx=nx+dx[j], nny=ny+dy[j];
        if(!isRange(nnx,nny,W,H))continue;
        if(dist[nny][nnx]==-1)continue;
        if(dist[nny][nnx]<score)cnt++;
      }
      if(cnt>=2)continue;
      G[ny][nx]='#';
      dist[ny][nx]=score;
      res++;
      q.push({nx,ny});
    }
  }

  cout<<res<<endl;
  // for(ll i=0;i<H;i++)cout<<G[i]<<endl;
  return 0;
}