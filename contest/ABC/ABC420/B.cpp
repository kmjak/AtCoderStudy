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
 * 最大の番号を答えるだけなら
 * 全員に1を足すという処理は足さないのと同義なので
 * 0と1の数を数えて少ない方の各人に1を足す
 * 最後に最大値と同じ数値の人を全員出力すれば良い
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,M;
  cin>>N>>M;
  vll A(N);
  vs S(N);
  for(ll i=0;i<N;i++){
    cin>>S[i];
  }

  for(ll i=0;i<M;i++){
    vll z,o;
    for(ll j=0;j<N;j++){
      if(S[j][i]=='0')z.eb(j);
      else o.eb(j);
    }
    if(z.size()<o.size()){
      for(auto j:z)A[j]++;
    }else{
      for(auto j:o)A[j]++;
    }
  }
  ll mx=*max_element(all(A));
  for(ll i=0;i<N;i++){
    if(A[i]==mx)cout<<i+1<<" ";
  }
  cout<<endl;

  return 0;
}