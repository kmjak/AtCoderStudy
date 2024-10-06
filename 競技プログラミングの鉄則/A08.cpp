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

  // TLEになる前提
  // int H,W;
  // cin >> H >> W;
  // vvi X(H,vi(W,0));
  // rep(i,0,H){
  //   rep(j,0,W) cin >> X[i][j];
  // }
  // int Q;
  // cin >> Q;
  // while(Q--){
  //   int sum = 0;
  //   pair<int,int> l,r;
  //   cin >> l.first >> l.second >> r.first >> r.second;
  //   l.first--;
  //   l.second--;
  //   // r.first--;
  //   // r.second--;

  //   rep(i,l.first,r.first){
  //     rep(j,l.second,r.second){
  //       sum += X[i][j];
  //     }
  //   }
  //   cout << sum << endl;
  // }
  int H,W;
  cin >> H >> W;
  vvi X(H+1,vi(W+1,0));
  rep(i,1,H+1){
    rep(j,1,W+1){
      int x;
      cin >> x;
      X[i][j] += X[i-1][j] + x;
    }
  }
  int Q;
  cin >> Q;
  while(Q--){
    pair<int,int> l,r;
    cin >> l.first >> l.second >> r.first >> r.second;
    int sum = 0;
    l.first--;
    rep(i,l.second,r.second+1){
      sum += X[r.first][i] - X[l.first][i];
      // cout << X[r.first][i] << " ";
    }
    cout << sum << endl;
  }
  return 0;
}