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

ll f(ll x, ll c)
{
  if(c % 2 == 0) return (x + x - c + 1) * (c / 2);
  return (x + x - c + 1) * (c / 2) + (x - c / 2);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // int N,M;
  // cin >> N >> M;
  // vi X(M),A(M),field(N,0);
  // vcin(M,X);
  // vcin(M,A);
  // rep(i,0,M) {
  //   field[X[i]-1] = A[i];
  // }
  // ll res = 0;
  // rep(i,0,N) {
  //   if(field[i] != 0){
  //     res += field[i];
  //     field[i+1] += field[i] - 1;
  //   }
  // }
  // cout << res << '\n';

  // int N,M;
  // cin >> N >> M;
  // vi X(M),A(M);
  // vcin(M,X);
  // vcin(M,A);
  // ll res = 0;
  // rep(i,0,M-1) {
  //   int tmp = A[i] - (X[i+1] - X[i]);
  //   if(tmp < 0){
  //     cout << -1 << '\n';
  //     return 0;
  //   }
  //   res += f(A[i]-1,X[i+1] - X[i]);
  //   A[i+1] += tmp;
  //   // cout << max(0,A[i] - (X[i+1] - X[i])) << '\n';
  // }
  // // vcout(A);
  // int tmp = A.back();
  // if(tmp < 0){
  //   cout << -1 << '\n';
  //   return 0;
  // }
  // res += f(A.back(),N - X.back()-1);
  // cout << res << '\n';

  // int N,M;
  // cin >> N >> M;
  // vi X(M),A(M);
  // vcin(M,X);
  // vcin(M,A);
  // ll res = 0;
  // rep(i,0,M-1) {
  //   int need = X[i + 1] - X[i];
  //   if(need > A[i]) {
  //     cout << -1 << '\n';
  //     return 0;
  //   }
  //   res += f(A[i]-1,need-1);
  // }
  // res += f(A.back()-1,N - X.back());
  // cout << res << '\n';

  // int N,M;
  // cin >> N >> M;
  // vi X(M),A(M);
  // vcin(M,X);
  // vcin(M,A);
  // ll res = 0;
  // rep(i,0,M-1) {

  // }

  // int N,M;
  // cin >> N >> M;
  // vector<pair<ll,ll>> X(M);
  // rep(i,0,M) {
  //   cin >> X[i].first;
  // }
  // rep(i,0,M) {
  //   cin >> X[i].second;
  // }
  // sort(all(X));
  // ll res = 0;
  // rep(i,0,M-1) {
  //   int need = X[i + 1].first - X[i].first;
  //   if(need > X[i].second) {
  //     cout << -1 << '\n';
  //     return 0;
  //   }
  //   res += f(X[i].second-1,need);
  //   X[i+1].second += X[i].second - need;
  // }
  // int need = N - X.back().first;
  // if(need > X.back().second) {
  //   cout << -1 << '\n';
  //   return 0;
  // }
  // res += f(X.back().second-1,N - X.back().first);
  // cout << res << '\n';
  // return 0;
  ll N,M;
  cin >> N >> M;
  vector<pair<ll,ll>> X(M);
  rep(i,0,M) {
    cin >> X[i].first;
  }
  rep(i,0,M) {
    cin >> X[i].second;
  }
  sort(all(X));
  ll sum = 0;
  ll current = 0;
  rep(i,0,M) {
    if(sum < X[i].first - 1){
      cout << -1 << '\n';
      return 0;
    }
    sum += X[i].second;
    current += X[i].second * X[i].first;
  }
  if (sum != N) {
    cout << -1 << endl;
    return 0;
  }
  cout << N * (N + 1) / 2 - current << '\n';
 return 0;
}