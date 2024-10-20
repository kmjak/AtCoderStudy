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
#define mt make_tuple
#define g(i,t) get<i>(t)
#define fi first
#define se second

#define NO cout << "No" << endl;
#define YES cout << "Yes" << endl;

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;

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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<vector<pair<int,bool>>> A(3, vector<pair<int,bool>>(3));
  rep(i,0,3) {
    rep(j,0,3) {
      int tmp;
      cin >> tmp;
      A[i][j] = mp(tmp,false);
    }
  }
  int N;
  cin >> N;
  rep(i,0,N) {
    int b;
    cin >> b;
    rep(j,0,3) {
      rep(k,0,3) {
        if(A[j][k].fi == b) A[j][k].se = true;
      }
    }
  }

  bool t = true;
  bool y = true;
  bool l = true;
  bool r = true;
  rep(i,0,3) {
    t = true;
    y = true;
    rep(j,0,3) {
      if(!A[i][j].se){
        t = false;
      }
      if(!A[j][i].se){
        y = false;
      }
    }
    if(t || y){
      YES;
      return 0;
    }
  }
  rep(i,0,3) {
    if(!A[i][i].se){
      l = false;
    }
    if(!A[2-i][i].se){
      r = false;
    }
  }
  if(r || l){
    YES;
  }else{
    NO;
  }
  return 0;
}