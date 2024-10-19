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

// int bfs(vvi &G, int n){
//   vi dist(n,-1);
//   queue<pi> q;
//   q.push(mp(0,-1));
//   dist[0] = 1;
//   while(!q.empty()){
//     auto [v,p] = q.front();
//     q.pop();
//     repa(u,G[v]){
//       if(u == 0){
//         return dist[v] + 1;
//       }
//       dist[u] = v;
//       q.push(mp(u,v));
//     }
//   }
//   return -1;
// }

// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   int N,M;
//   cin >> N >> M;
//   vvi G(N);
//   rep(i,0,M){
//     int a,b;
//     cin >> a >> b;
//     a--;
//     b--;
//     G[a].pb(b);
//   }
//   cout << bfs(G,N) << endl;
//   return 0;
// }

int bfs(vvi &G,int N){
  vi dist(N+1,INT_MAX);
  dist[0] = 0;
  queue<int> q;
  q.push(0);

  while(!q.empty()){
    int v = q.front();
    q.pop();

    repa(x,G[v]){
      if(x == 0){
        return dist[v] + 1;
      }
      if(dist[x] == INT_MAX){
        dist[x] = dist[v] + 1;
        q.push(x);
      }
    }
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,M;
  cin >> N >> M;
  vvi G(N);
  rep(i,0,M){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].pb(b);
  }
  cout << bfs(G,N) << endl;
  return 0;
}