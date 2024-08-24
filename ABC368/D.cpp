#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define rep(i, s, n) for(int i = s; i < n; i++)
using namespace std;

vvi adj; // 隣接リスト
vi dist, parent, subtree_size;
vector<bool> is_in_v;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int calculate_subtree(int u) {
    subtree_size[u] = is_in_v[u] ? 1 : 0;

    for (int v : adj[u]) {
        if (v != parent[u]) {
            parent[v] = u;
            subtree_size[u] += calculate_subtree(v);
        }
    }

    return subtree_size[u];
}

int main() {
    int n, k;
    cin >> n >> k;

    adj.resize(n + 1);
    dist.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    subtree_size.assign(n + 1, 0);
    is_in_v.assign(n + 1, false);

    vi a(n-1), b(n-1), v(k);
    rep(i, 0, n-1) {
        cin >> a[i] >> b[i];
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    rep(i, 0, k) {
        cin >> v[i];
        is_in_v[v[i]] = true;
    }

    bfs(v[0]);

    calculate_subtree(v[0]);

    int result = 0;
    rep(i, 1, n + 1) {
        if (subtree_size[i] > 0) result++;
    }

    cout << result << endl;
    return 0;
}