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

set<pair<int,int>> G_edges, H_edges;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, MG, MH;
  cin >> N >> MG;

  for(;MG--;){
    int u,v;
    cin>> u >> v;
    u--; v--;
    G_edges.insert({u, v});
    G_edges.insert({v, u});
  }

  cin>> MH;
  for(int i=0;i<MH;i++){
    int u,v;
    cin>> u >> v;
    u--; v--;
    H_edges.insert({u, v});
    H_edges.insert({v, u});
  }

  vvi Costs(N, vi(N, 0));
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      cin>> Costs[i][j];
      Costs[j][i] = Costs[i][j];
    }
  }

  vi P(N);
  iota(all(P), 0);

  int res = 1e9;
  do {
    int sum = 0;
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        if (G_edges.count({i, j}) == H_edges.count({P[i], P[j]})) {
          continue;
        }
        sum += Costs[P[i]][P[j]];
      }
    }
    // cout << "sum: " << sum << endl;
    chmin(res, sum);
  } while (next_permutation(all(P)));
  cout << res << endl;
  return 0;
}