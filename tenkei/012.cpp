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

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;
ll H,W;
vb vis(2010*2010, false);

class UnionFind {
  public:
    UnionFind() = default;

    explicit UnionFind(int n) : parent_or_size(n, -1) {}

    int find(int x) {
      if (parent_or_size[x] < 0) return x;
      return parent_or_size[x] = find(parent_or_size[x]);
    }

    bool merge(int a, int b) {
      a = find(a);
      b = find(b);
      if (a == b) return false;
      if (-parent_or_size[a] < -parent_or_size[b]) swap(a, b);
      parent_or_size[a] += parent_or_size[b];
      parent_or_size[b] = a;
      return true;
    }

    bool connected(int a, int b) {
      return find(a) == find(b);
    }

    int size(int x) {
      return -parent_or_size[find(x)];
    }

  private:
    vector<int> parent_or_size;
};

bool isRange(ll x, ll y)
{
  return 0<=x&&x<W&&0<=y&&y<H;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll Q;cin>>H>>W>>Q;
  UnionFind uf(H*W);
  while(Q--){
    ll opt;cin>>opt;
    if(opt==1){
      ll y,x;cin>>y>>x;
      x--;y--;
      vis[y*W+x]=true;
      for(ll i=0;i<4;i++){
        ll nx=x+dx[i], ny=y+dy[i];
        if(isRange(nx,ny)&&vis[ny*W+nx]){
          uf.merge(y*W+x, ny*W+nx);
        }
      }
    }else{
      ll stx, sty, glx, gly;
      cin>>sty>>stx>>gly>>glx;
      stx--;sty--;glx--;gly--;

      if(uf.connected(sty*W+stx, gly*W+glx)&&vis[sty*W+stx]&&vis[gly*W+glx]){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }
  }
  return 0;
}