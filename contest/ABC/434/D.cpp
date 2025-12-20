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

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

/**
 * 考察
 * 雲が重なっていない場所の数をカウント(latest)
 * 次に、1箇所だけ雲が重なってる場所を2次元累積和で記録
 * 最後にk=1..Nの雲kが覆っている場所かつ1箇所だけ雲が重なってる場所の数を記録(add)
 * 最後にlatest+addを出力
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll mod=1e9+7;
const ll inf=1e18;
const ll m2000=2000;
const ll mx=m2000+10;
vvll G(mx,vll(mx));

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N;cin>>N;
  vll U(N),D(N),L(N),R(N);
  for(ll i=0;i<N;i++){
    cin>>U[i]>>D[i]>>L[i]>>R[i];
    G[U[i]-1][L[i]-1]++;
    G[D[i]][L[i]-1]--;
    G[U[i]-1][R[i]]--;
    G[D[i]][R[i]]++;
  }

  for(ll i=0;i<m2000;i++){
    for(ll j=0;j<m2000;j++){
      G[i][j+1]+=G[i][j];
    }
  }
  for(ll i=0;i<m2000;i++){
    for(ll j=0;j<m2000;j++){
      G[j+1][i]+=G[j][i];
    }
  }

  ll latest=0;
  for(ll i=0;i<m2000;i++){
    for(ll j=0;j<m2000;j++)latest+=(G[i][j]==0);
  }

  vvll imos(mx,vll(mx));
  for(ll i=1;i<=m2000;i++){
    for(ll j=1;j<=m2000;j++){
      imos[i][j]=(G[i-1][j-1]==1);
    }
  }
  for(ll i=1;i<=m2000;i++){
    for(ll j=1;j<=m2000;j++){
      imos[i][j]+=imos[i][j-1];
    }
  }
  for(ll j=1;j<=m2000;j++){
    for(ll i=1;i<=m2000;i++){
      imos[i][j]+=imos[i-1][j];
    }
  }
  for(ll i=0;i<N;i++){
    ll u=U[i],d=D[i],l=L[i],r=R[i];

    ll add=imos[d][r]-imos[u-1][r]-imos[d][l-1]+imos[u-1][l-1];
    cout<<latest+add<<endl;
  }
  return 0;
}