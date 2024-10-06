#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
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
  int n,m,q;
  cin >> n >> m >> q;
  vvi G(n+1);
  rep(i,0,m){
    int u,v;
    cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  vi c(n+1);
  rep(i,1,n+1) cin >> c[i];

  while(q--){
    int option,x;
    cin >> option >> x;
    cout << c[x] << endl;
    if(option == 1){
      repa(X,G[x]){
        c[X] = c[x];
      }
    }else{
      int X;
      cin >> X;
      c[x] = X;
    }
  }
  return 0;
}