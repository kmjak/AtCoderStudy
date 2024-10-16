#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

using ll=long long int;
using pi=pair<int,int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;

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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,MG;
  cin >> N >> MG;
  vvi G(N),H(G);
  rep(i,0,MG){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    G[u].pb(v);
    G[v].pb(u);
  }
  int MH;
  cin >> MH;
  rep(i,0,MH){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    H[u].pb(v);
    H[v].pb(u);
  }
  vvi A(N);
  rep(i,0,N-1){
    rep(j,i+1,N){
      int x;
      cin >> x;
      A[i].pb(x);
      A[x].pb(i);
    }
  }
  int res = INT_MAX;

  vi pattern(N);
  rep(i,0,N) pattern[i] = i;

  do
  {
    rep(i,0,N){
    }
  } while (next_permutation(all(pattern)));
  
  cout << res << endl;
  return 0;
}