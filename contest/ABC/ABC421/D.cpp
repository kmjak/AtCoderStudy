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
 * 絶対に解けた。
 * M,Lが違う可能性があるので一見難しそうに見えたけど
 * TiとAjの合計値が一緒であるから
 * TiとAjの小さい方の値を使って移動させていけば良い
 * TとAが同じ位置かつ同じ向きであればres+=m
 * また、交差するのであればres+1
 *
 * ただ解ききれなかった
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pair<ll,ll> T,A;
  cin>>T.first>>T.second>>A.first>>A.second;
  ll N,M,L;cin>>N>>M>>L;
  if((T.first+A.first)%2 || (T.second+A.second)%2){
    cout<<0<<endl;
    return 0;
  }


  pair<ll, ll> Mi={(T.first+A.first)/2, (T.second+A.second)/2};

  vector<pair<char,ll>> Tm(M), Am(L);
  for(ll i=0;i<M;i++)cin>>Tm[i].first>>Tm[i].second;
  for(ll i=0;i<L;i++)cin>>Am[i].first>>Am[i].second;

  ll curT=0, curA=0;
  ll res=0;
  while(curT<M && curA<L){
    ll m=min(Tm[curT].second, Am[curA].second);
    if(T==A){
      if(Tm[curT].first==Am[curA].first){
        res+=m;
      }

      if(Tm[curT].first=='R'){
        T.second+=m;
      }
      if(Tm[curT].first=='L'){
        T.second-=m;
      }
      if(Tm[curT].first=='D'){
        T.first+=m;
      }
      if(Tm[curT].first=='U'){
        T.first-=m;
      }
      if(Am[curA].first=='R'){
        A.second+=m;
      }
      if(Am[curA].first=='L'){
        A.second-=m;
      }
      if(Am[curA].first=='D'){
        A.first+=m;
      }
      if(Am[curA].first=='U'){
        A.first-=m;
      }

      Tm[curT].second-=m;
      Am[curA].second-=m;
      Mi = {(T.first+A.first)/2, (T.second+A.second)/2};
      if(Tm[curT].second==0)curT++;
      if(Am[curA].second==0)curA++;
      continue;
    }
    pair<ll,ll> diffT={Mi.first - T.first, Mi.second - T.second};
    pair<ll,ll> diffA={Mi.first - A.first, Mi.second - A.second};
    ll wT=-1, wA=-1;
    if(Tm[curT].first=='R'){
      if(diffT.second<0&&abs(diffT.second)<=m)wT=m-abs(diffT.second);
    }
    if(Tm[curT].first=='L'){
      if(diffT.second>0&&abs(diffT.second)<=m)wT=m-abs(diffT.second);
    }
    if(Tm[curT].first=='D'){
      if(diffT.first<0&&abs(diffT.first)<=m)wT=m-abs(diffT.first);
    }
    if(Tm[curT].first=='U'){
      if(diffT.first>0&&abs(diffT.first)<=m)wT=m-abs(diffT.first);
    }
    if(Am[curA].first=='R'){
      if(diffA.second<0&&abs(diffA.second)<=m)wA=m-abs(diffA.second);
    }
    if(Am[curA].first=='L'){
      if(diffA.second>0&&abs(diffA.second)<=m)wA=m-abs(diffA.second);
    }
    if(Am[curA].first=='D'){
      if(diffA.first<0&&abs(diffA.first)<=m)wA=m-abs(diffA.first);
    }
    if(Am[curA].first=='U'){
      if(diffA.first>0&&abs(diffA.first)<=m)wA=m-abs(diffA.first);
    }
    if(wT!=-1&&wA!=-1){
      res+=(wT==wA);
    }

    Tm[curT].second-=m;
    Am[curA].second-=m;
    if(Tm[curT].first=='R'){
      T.second+=m;
    }
    if(Tm[curT].first=='L'){
      T.second-=m;
    }
    if(Tm[curT].first=='D'){
      T.first+=m;
    }
    if(Tm[curT].first=='U'){
      T.first-=m;
    }
    if(Am[curA].first=='R'){
      A.second+=m;
    }
    if(Am[curA].first=='L'){
      A.second-=m;
    }
    if(Am[curA].first=='D'){
      A.first+=m;
    }
    if(Am[curA].first=='U'){
      A.first-=m;
    }
    Mi = {(T.first+A.first)/2, (T.second+A.second)/2};

    if(Tm[curT].second==0)curT++;
    if(Am[curA].second==0)curA++;
    // cout<<P.first<<" "<<P.second<<endl;
  }
  cout<<res<<endl;
  return 0;
}