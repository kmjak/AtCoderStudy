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
  public:
  set<pair<ll,ll>> intervals;
  ll covered_length = 0;
  ll infinity = 1e18;

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
};

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

/**
 * 考察
 *
 */

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll mod=1e9+7;
const ll inf=1e18;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll H,W;cin>>H>>W;
  vs G(H);
  for(ll i=0;i<H;i++){
    string s;cin>>s;
    G[i]=s;
  }

  queue<pair<ll,ll>> q;
  vector<vb> vis(H,vb(W));
  ll wc=0;
  for(ll i=0;i<H;i++){
    for(ll j=0;j<W;j++){
      if(G[i][j]=='.'&&vis[i][j]==false){
        q.push(mp(i,j));
        vis[i][j]=true;
        wc++;
        while(!q.empty()){
          auto [y,x]=q.front();q.pop();
          for(ll k=0;k<4;k++){
            ll nx=x+dx[k];
            ll ny=y+dy[k];
            if(!isRange(nx,ny,W,H))continue;
            if(vis[ny][nx])continue;
            if(G[ny][nx]=='#')continue;

            vis[ny][nx]=true;
            q.push(mp(ny,nx));
          }
        }
      }
    }
  }

  // cout<<wc<<endl;
  // for(auto v: vis){
  //   for(auto x: v){
  //     cout<<x<<" ";
  //   }
  //   cout<<endl;
  // }

  ll ig=0;
  vector<vb> v(H,vb(W));
  for(ll i=0;i<W;i++){
    if(G[0][i]=='.'&&v[0][i]==false){
      q.push(mp(0,i));
      v[0][i]=true;
      ig++;
      while(!q.empty()){
        auto [y,x]=q.front();q.pop();
        for(ll k=0;k<4;k++){
          ll nx=x+dx[k];
          ll ny=y+dy[k];
          if(!isRange(nx,ny,W,H))continue;
          if(v[ny][nx])continue;
          if(G[ny][nx]=='#')continue;

          v[ny][nx]=true;
          q.push(mp(ny,nx));
        }
      }
    }
    if(G[H-1][i]=='.'&&v[H-1][i]==false){
      q.push(mp(H-1,i));
      v[H-1][i]=true;
      ig++;
      while(!q.empty()){
        auto [y,x]=q.front();q.pop();
        for(ll k=0;k<4;k++){
          ll nx=x+dx[k];
          ll ny=y+dy[k];
          if(!isRange(nx,ny,W,H))continue;
          if(v[ny][nx])continue;
          if(G[ny][nx]=='#')continue;

          v[ny][nx]=true;
          q.push(mp(ny,nx));
        }
      }
    }
  }

  for(ll i=0;i<H;i++){
    if(G[i][0]=='.'&&v[i][0]==false){
      q.push(mp(i,0));
      v[i][0]=true;
      ig++;
      while(!q.empty()){
        auto [y,x]=q.front();q.pop();
        for(ll k=0;k<4;k++){
          ll nx=x+dx[k];
          ll ny=y+dy[k];
          if(!isRange(nx,ny,W,H))continue;
          if(v[ny][nx])continue;
          if(G[ny][nx]=='#')continue;

          v[ny][nx]=true;
          q.push(mp(ny,nx));
        }
      }
    }
    if(G[i][W-1]=='.'&&v[i][W-1]==false){
      q.push(mp(i,W-1));
      v[i][W-1]=true;
      ig++;
      while(!q.empty()){
        auto [y,x]=q.front();q.pop();
        for(ll k=0;k<4;k++){
          ll nx=x+dx[k];
          ll ny=y+dy[k];
          if(!isRange(nx,ny,W,H))continue;
          if(v[ny][nx])continue;
          if(G[ny][nx]=='#')continue;

          v[ny][nx]=true;
          q.push(mp(ny,nx));
        }
      }
    }
  }

  cout<<wc-ig<<endl;

  return 0;
}