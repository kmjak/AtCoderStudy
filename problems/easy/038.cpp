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

#define sort(x) sort(all(x))
#define rsort(x) sort(rall(x))

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
  // 全探査を使わない方法で解いてみた
  // vi Menu(5);
  // vcin(5,Menu);
  // int last_i = 0;
  // int m = toi(string(1, tos(Menu[0]).back()));
  // rep(i,1,5) {
  //   string tmp_s = tos(Menu[i]);
  //   int t = toi(string(1, tmp_s.back()));
  //   if(t == 0) continue;
  //   if(chmin(m,t)){
  //     last_i = i;
  //   }
  // }
  // int sum = 0;
  // rep(i,0,5) {
  //   if(last_i != i) sum += Menu[i] + (10-Menu[i]%10)%10;
  // }
  // cout << sum + Menu[last_i] << '\n';

  // そもそも全探査がいらないことに気がついた
  vi Menu(5);
  vcin(5,Menu);
  int res = INT_MAX;
  rep(i,0,5) {
    int sum = 0;
    rep(j,0,5) {
      if(j != i){
        sum += Menu[j] + (10 - Menu[j] % 10) % 10;
      }
    }
    sum += Menu[i];
    chmin(res,sum);
  }

  cout << res << '\n';
  return 0;
}