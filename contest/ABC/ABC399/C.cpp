#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

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
vvi G(2e5+10);
vb visited(2e5+10, false);
int res=0;

void bfs(int st, int &n, int &k) {
  queue<int> q;
  q.push(st);
  visited[st] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    n++;

    for (int v : G[u]) {
      k++;
      if (!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 1; i <= N; ++i) {
    if (!visited[i]) {
      int n=0;
      int k=0;
      bfs(i, n, k);
      k/=2;
      res+=k-(n-1);
    }
  }

  cout << res << endl;
  return 0;
}