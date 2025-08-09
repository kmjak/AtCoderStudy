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
 *
 */

struct que{
  pair<ll,ll> pos;
  ll sc;
  ll p;
};

ll H, W;
vs G(1010);
pair<ll,ll> st,gl;

ll bfs(){
  queue<que> q;
  vvll distP0(H,vll(W,-1));
  vvll distP1(H,vll(W,-1));
  distP0[st.first][st.second]=0;
  q.push({st, 0, 0});
  for(ll i=-1;i<2;i+=2){
    ll nx = st.second + i;
    ll ny = st.first;
    if(!isRange(nx, ny, W, H))continue;
    if(G[ny][nx]=='#')continue;
    q.push({mp(ny, nx), 0, 1});
    distP1[ny][nx] = 1;
  }

  while(!q.empty()){
    auto [pos, sc, p] = q.front();
    auto [y, x] = pos;
    q.pop();
    if(pos == gl){
      if(p == 0) return distP0[y][x];
      else return distP1[y][x];
    }
    for(ll i=0;i<4;i++){
      if(i%2==sc%2)continue;
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if(!isRange(nx, ny, W, H))continue;
      if(G[ny][nx]=='#')continue;
      if(p==0){
        if(distP0[ny][nx] != -1)continue;
        distP0[ny][nx] = distP0[y][x] + 1;
      }else{
        if(distP1[ny][nx] != -1)continue;
        distP1[ny][nx] = distP1[y][x] + 1;
      }
      q.push({mp(ny, nx), sc + 1, p});
    }
  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>H>>W;
  for(ll i=0; i<H; i++){
    cin>>G[i];
    for(ll j=0;j<W;j++){
      if(G[i][j]=='S')st=mp(i,j);
      if(G[i][j]=='G')gl=mp(i,j);
    }
  }
  cout<<bfs()<<endl;
  return 0;
}