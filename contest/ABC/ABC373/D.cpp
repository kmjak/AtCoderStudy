#include <bits/stdc++.h>

#define ll long long int
#define vi vector<ll>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define vvs vector<vs>
#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define repra(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int main()
{
  ll n, m;
  cin >> n >> m;
  ll u, v, w;

  vector<vector<pair<ll, ll>>> adj(n + 1);

  rep(i, 0, m) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, -w});
  }

  vi x(n + 1, LLONG_MAX);
  queue<ll> q;

  x[1] = 0;
  q.push(1);

  while (!q.empty()) {
    ll curr = q.front();
    q.pop();

    for (auto [next, weight] : adj[curr]) {
      if (x[next] == LLONG_MAX) {
        x[next] = x[curr] + weight;
        q.push(next);
      } else if (x[next] != x[curr] + weight) {
        return 0;
      }
    }
  }

  rep(i, 1, n + 1) {
    cout << x[i] << " ";
  }
  cout << endl;

  return 0;
}