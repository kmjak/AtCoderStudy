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

vvi G(2e5+10);
int N,M;


bool bfs()
{
  qi q;
  vb visited(N, false);
  q.push(0);
  visited[0] = true;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto nv : G[v]){
      if(!visited[nv]){
        visited[nv] = true;
        q.push(nv);
      }
    }
  }

  for(int i=0;i<N;i++){
    if(!visited[i]){
      return false;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;

  for(int i=0;i<M;i++){
    int u,v;
    cin >> u >> v;
    u--; v--;
    G[u].eb(v);
    G[v].eb(u);
  }

  if(bfs()){
    for(int i=0;i<N;i++){
      if(G[i].size() != 2){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }
  cout<< "No" << endl;

  return 0;
}