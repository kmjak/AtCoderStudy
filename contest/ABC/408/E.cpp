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

int N,M;
ll res = LLONG_MAX;
vector<vector<pair<int,ll>>> G(2e5+10);

void dfs(vb &vis, ll score, int cur, int idx)
{
  // if(idx == N) {
  //   cout<< "score :"<< score << endl;
  //   chmin(res,score);
  // }
  
  bool isEnd = true;

  for(auto v: G[cur]) {
    if(vis[v.first]) {
      continue;
    }
    isEnd = false;
    vis[v.first] = true;
    dfs(vis, score | v.second, v.first, idx+1);
    vis[v.first] = false;
  }

  if(isEnd) {
    chmin(res, score);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    G[u].eb(v, w);
    G[v].eb(u, w);
  }

  vb vis(N, false);
  vis[0] = true;
  dfs(vis, 0, 0, 1);
  cout << res << endl;
  return 0;
}