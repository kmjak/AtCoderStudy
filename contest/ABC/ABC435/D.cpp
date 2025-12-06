#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back

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
  vector<pair<ll,bool>> parent;
  vll size;

  UnionFind(ll n) : parent(n, {-1,false}), size(n, 1) {}

  ll find(ll x, ll s) {
    if (parent[x].first == -1||parent[x].first==s) return x;
    return parent[x].first = find(parent[x].first, s);
  }

  bool unite(ll a, ll b) {
    a = find(a, a);
    b = find(b, b);
    if (a == b) return false;
    // if (size[a] < size[b]) swap(a, b);
    parent[b].first = a;
    parent[a].second=parent[a].second||parent[b].second;
    size[a] += size[b];
    return true;
  }

  bool same(ll a, ll b) {
    return find(a, a) == find(b, b);
  }

  ll getSize(ll x) {
    return size[find(x, x)];
  }

  bool getHasBlack(ll x){
    return parent[find(x, x)].second;
  }

  bool draw(ll x){
    x = find(x, x);
    parent[x].second=true;
    return true;
  }
};

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

/**
 * 考察
 * 間に合わなかった。
 * union findや事前にbfsで有向グラフの中で事前に親を決めたりして解いたがダメだった。
 *
 * 結局、黒く塗られるたびにbfsで探索すればよかった。
 * 工夫として、すでに黒く塗られているところに到達可能な場所はスキップする
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll mod=1e9+7;
const ll inf=1e18;
vvll G(3e5+10);
ll N,M;

void bfs(vb &isBlack, ll st){
  queue<ll> q;
  q.push(st);

  while(!q.empty()){
    ll cur=q.front();q.pop();
    isBlack[cur]=true;

    for(auto nx: G[cur]){
      if(isBlack[nx])continue;
      q.push(nx);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>M;

  for(ll i=0;i<M;i++){
    ll u,v;cin>>u>>v;
    u--;v--;
    G[v].eb(u);
  }


  vb isBlack(N);
  ll Q;cin>>Q;
  while(Q--){
    ll opt,v;cin>>opt>>v;v--;
    if(opt==1){
      if(isBlack[v])continue;
      bfs(isBlack, v);
    }else{
      cout<<(isBlack[v]?"Yes":"No")<<endl;
    }
  }
  return 0;
}