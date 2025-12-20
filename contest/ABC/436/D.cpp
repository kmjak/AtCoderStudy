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

class IntervalSet {
  set<pair<ll,ll>> intervals;
  ll covered_length = 0;
  ll infinity = 1e18;

public:
  bool merge(ll l, ll r){
    auto it = intervals.lower_bound({l, infinity});
    if(it!=intervals.begin()){
      it--;
      if(it->second<l-1)it++;
    }
    while(it != intervals.end() && it->first <= r + 1) {
      chmin(l, it->first);
      chmax(r, it->second);
      covered_length -= (it->second - it->first + 1);
      it=intervals.erase(it);
    }
    covered_length+=(r-l+1);
    return intervals.insert({l,r}).second;
  }

  set<pair<ll,ll>> getIntervals() {
    return intervals;
  }

  ll coveredLength() {
    return covered_length;
  }

  size_t count() {
    return intervals.size();
  }
};

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

/**
 * 考察
 * bfsでgoalに最短で行くまでの回数を数えるだけ
 * 注意として一度使ったwarp pointを何度も使用すると
 * TLEになるのでチェック
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll mod=1e9+7;
const ll inf=1e18;
vs G(1010);
map<char,set<pair<ll,ll>>> wp;
set<char> used;

ll bfs(ll h, ll w){
  queue<pair<ll,ll>> q;
  vvll dist(h,vll(w,-1));

  q.push({0,0});
  dist[0][0]=0;
  if(!(G[0][0]=='.'||G[0][0]=='#')){
    used.insert(G[0][0]);
    for(auto [wy, wx]: wp[G[0][0]]){
      if(dist[wy][wx]!=-1)continue;
      dist[wy][wx]=1;
      q.push({wy,wx});
    }
  }

  while(!q.empty()){
    auto [y, x]=q.front();q.pop();

    for(ll i=0;i<4;i++){
      ll nx=x+dx[i];
      ll ny=y+dy[i];

      if(!isRange(nx,ny,w,h))continue;
      if(dist[ny][nx]!=-1)continue;
      if(G[ny][nx]=='#')continue;

      dist[ny][nx]=dist[y][x]+1;
      q.push({ny,nx});
    }
    if(!(G[y][x]=='.'||G[y][x]=='#')){
      if(used.count(G[y][x]))continue;
      used.insert(G[y][x]);

      for(auto [wy, wx]: wp[G[y][x]]){
        if(dist[wy][wx]!=-1)continue;

        dist[wy][wx]=dist[y][x]+1;
        q.push({wy,wx});
      }
    }
  }

  // for(ll i=0;i<h;i++){
  //   for(ll j=0;j<w;j++){
  //     cout<<dist[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  return dist[h-1][w-1];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll H,W;cin>>H>>W;
  for(ll i=0;i<H;i++){
    string s;cin>>s;
    G[i]=s;
    for(ll j=0;j<W;j++)if(!(s[j]=='.'||s[j]=='#'))wp[s[j]].insert({i,j});
  }

  ll res=bfs(H,W);
  cout<<res<<endl;
  return 0;
}