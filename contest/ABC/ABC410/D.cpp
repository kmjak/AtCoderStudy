#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

using vvi=vector<vi>;
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

struct pnt {
  ll x;
  ll y;
};

ll N,M;
vector<vector<pair<ll,ll>>> G(1010);
vll W(1010);

ll res = LLONG_MAX;

void dfs(ll cur, string used, string vis, ll score)
{
  if(cur == N-1){
    if(vis == string(N, '1')) {
      chmin(res, score);
      return;
    }
  }

  for(auto e : G[cur]){
    auto [next, ni] = e;
    if(used[ni] == '1') continue;
    used[ni]='1';
    vis[next]='1';
    dfs(next, used, vis, score ^ W[ni]);
    vis[next]='0';
    used[ni]='0';
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>M;

  for(ll i=0;i<M;i++){
    ll u,v,w;
    cin>>u>>v>>w;
    u--; v--;
    G[u].eb(mp(v,i));
    G[v].eb(mp(u,i));
    W[i]=w;
  }
  string used(M, '0');
  string vis(N, '0');
  vis[0] = '1';
  dfs(0, used, vis ,0LL);

  cout << (res == LLONG_MAX ? -1 : res) << endl;
  return 0;
}