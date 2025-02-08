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
  vi vec;
  ll K;
};

long double res=0.0;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vvll A(110,vll (1e5+20,0));
  vll K(N),Ac(N);
  rep(i,0,N){
    cin >> K[i];
    ll MAX=0;
    rep(j,0,K[i]){
      ll a;
      cin >> a;
      A[i][a]++;
      chmax(MAX,a);
    }
    Ac[i]=MAX+1;
    rrep(j,i-1,-1){
      ll sum=0;
      ll p = max(Ac[i],Ac[j]);
      rep(k,0,p+1){
        if(A[i][k]!=0 && A[j][k]!=0){
          sum+=A[i][k]*A[j][k];
        }
      }
      chmax(res,(long double)sum/(K[i]*K[j]));
      // cout<<res<<endl;
    }
  }
  cout<<fixed<<setprecision(10)<<res<<endl;
  return 0;
}