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
  ll s;
  ll l;
};

int H,W;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>H>>W;
  vs G(H);
  rep(i,0,H) {
    cin>>G[i];
  }
  vector<pnt> p(H,{-1,-1});
  rep(i,0,H) {
    rep(j,0,W) {
      if(G[i][j]=='#'&&p[i].s==-1){
        p[i].s=j;
      }
      if(G[i][j]=='#'){
        p[i].l=j;
      }
    }
  }
  ll min_w=1010,max_w=-1,min_y=-1,max_y=-1;
  rep(i,0,H) {
    if(p[i].s!=-1)chmin(min_w,p[i].s);
    chmax(max_w,p[i].l);
    if(min_y==-1&&p[i].s!=-1)min_y=i;
    if(p[i].s!=-1)max_y=i;
  }
  rep(i,min_y,max_y+1) {
    rep(j,min_w,max_w+1) {
      if(G[i][j]=='.'){
        NO;
        return 0;
      }
    }
  }
  YES;
  return 0;
}