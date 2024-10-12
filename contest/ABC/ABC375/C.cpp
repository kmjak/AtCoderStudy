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

using namespace std;

using ll=long long int;
using pi=pair<int,int>;

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
  int N;
  cin >> N;
  vector<vc> c(N, vc(N));
  string s;
  rep(i,0,N){
    cin >> s;
    rep(j,0,N){
      c[i][j] = s[j];
    }
  }
  vector<vc> next(N, vc(N));
  next = c;
  rep(i,0,N/2){
  // rep(i,0,1){
    rep(j,i,N-i){
      rep(k,i,N-i){
        next[j][N-k-1] = c[k][j];
      }
    }
    c = next;
  }
  repa(x,c){
    repa(y,x){
      cout << y;
    }
    cout << endl;
  }
  return 0;
}