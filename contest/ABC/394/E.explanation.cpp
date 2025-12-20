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
  ll from;
  ll to;
};
int inf = 1e9+10;
int N;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N;
  vector<vc> c(N,vc(N));
  rep(i,0,N){
    rep(j,0,N)cin>>c[i][j];
  }
  vvi a(N,vi(N,inf));
  queue<pi> q;
  rep(i,0,N){
    q.push(mp(i,i));
    a[i][i]=0;
  }
  rep(i,0,N){
    rep(j,0,N){
      if(i==j||c[i][j]=='-')continue;
      q.push(mp(i,j));
      a[i][j]=1;
    }
  }
  while(!q.empty()){
    auto [i,j]=q.front();
    q.pop();
    rep(k,0,N){
      rep(l,0,N){
        if(c[k][i]!='-'&&c[j][l]!='-'&&c[k][i]==c[j][l]&&a[k][l]==inf) {
          a[k][l]=a[i][j]+2;
          q.push({k, l});
        }
      }
    }
  }
  rep(i,0,N){
    rep(j,0,N){
      cout<<(a[i][j]==inf?-1:a[i][j])<<" ";
    }
    cout<<endl;
  }
}