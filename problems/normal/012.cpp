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
#define toi(s) stoi(s)

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using si=set<int>;

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
  int H,W;
  cin >> H >> W;
  vs Grid(H);
  vector<bool> fillH(H,false);
  vector<bool> fillW(W,false);
  vcin(H,Grid);
  rep(i,0,W) {
    bool isEmpty = true;
    rep(j,0,H) {
      if(count(all(Grid[j]),'#') == 0){
        fillH[j] = true;
      }
      if(Grid[j][i] == '#'){
        isEmpty = false;
        break;
      }
    }
    if(isEmpty){
      fillW[i] = true;
    }
  }
  rep(i,0,H) {
    if(fillH[i]){
      continue;
    }
    rep(j,0,W) {
      if(fillW[j]){
        continue;
      }
      cout << Grid[i][j];
    }
    cout << '\n';
  }
  return 0;
}