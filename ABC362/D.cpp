#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define rep(i, s, n) for(int i = s; i < n; i++)
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>

int main() {
  int n, m;
  cin >> n >> m;
  vll A(n);
  rep(i, 0, n) {
    cin >> A[i];
  }
  
  vector<vector<pll>> adj(n);
  rep(i, 0, m) {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--;
    v--; 
    adj[u].emplace_back(v, b);
    adj[v].emplace_back(u, b);
  }

  vll dist(n, LLONG_MAX);
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dist[0] = A[0];
  pq.emplace(dist[0], 0);
  
  while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, b] : adj[u]) {
      ll new_dist = dist[u] + A[v] + b;
      if (new_dist < dist[v]) {
        dist[v] = new_dist;
        pq.emplace(new_dist, v);
      }
    }
  }

  rep(i, 1, n) {
    cout << dist[i] << " ";
  }
  cout << endl;

  return 0;
}