#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

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

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(A) rep(i,0,A.size()) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ')

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
  ll a;
  ll b;
};

vvi G(2*1e5+10),D(2*1e5+10);
vector<pnt> res;

void dfs(vb &dist, int s)
{
  dist[s] = true;
  repa(i,G[s]){
    if(dist[i]){
      D[s].pb(i);
      continue;
    }
    dfs(dist,i);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,M;
  cin >> N>>M;
  int s=-1;
  rep(i,0,M){
    int a,b;
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
    s=a;
  }
  bool flag = true;
  while(flag){
    vb dist(N+1,false);
    dfs(dist,s);
    int unvisited = -1;
    rep(i,1,N+1){
      if(!dist[i]){
        flag = false;
        unvisited = i;
        break;
      }
    }
    if(unvisited == -1) break;
    bool flag2 = false;
    rep(j,1,N+1){
      if(D[j].size() != 0){
        rep(k,1,D[j].size()+1){
          if(D[D[j][k]].size()!=0){
            int x = D[j][k];
            G[j].erase(remove(G[j].begin(), G[j].end(), x), G[j].end());
            G[D[j][k]].erase(remove(G[D[j][k]].begin(), G[D[j][k]].end(), j), G[D[j][k]].end());
            G[unvisited].pb(j);
            G[j].pb(unvisited);
            res.pb({j,unvisited});
            flag2 = true;
            break;
          }
        }
      }
      if(flag2) break;
    }
  }
  cout<<res.size()<<endl;
  repa(i,res){
    cout<<i.a<<" "<<i.b<<endl;
  }
  return 0;
}