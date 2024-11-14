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
  string S;
  cin >> S;
  int n = S.size();
  // vi sum(n+1,0);
  // int MIN = INT_MAX;
  // rep(i,0,n) {
  //   sum[i+1] = sum[i];
  //   if(S[i] == '>'){
  //     if(S[i+1] == '<'){
  //       sum[i+1] = MIN;
  //     }else{
  //       sum[i+1]--;
  //     }
  //     chmin(MIN,sum[i+1]);
  //   }else{
  //     sum[i+1]++;
  //   }
  // }
  // ll res = abs(MIN) * n;
  // repa(x,sum){
  //   cout << x + abs(MIN) << ' ';
  //   res += x;
  // }
  // cout << '\n';
  // cout << res << '\n';

  vi ans(n+1,0);
  rep(i,0,n) {
    if(S[i] == '<') ans[i+1] = ans[i] + 1;
  }

  rrep(i,n-1,-1){
    if (S[i] == '>') {
      chmax(ans[i],ans[i+1]+1);
    }
  }

  ll res2 = 0;
  rep(i,0,n+1) {
    res2 += ans[i];
  }

  // cout << res << '\n';
  return 0;
}