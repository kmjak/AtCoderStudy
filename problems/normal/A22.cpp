#include <bits/stdc++.h>

#define rt return

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
#define END cout << '\n'

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // int N,K;
  // cin >> N >> K;
  // vll tmp(N);
  // set<ll> used;
  // rep(i,1,N+1) {
  //   if(i > K){
  //     break;
  //   }
  //   // double need = (log(K) - log(i)) / log(2);
  //   // int need = ceil((log(K) - log(i)) / log(2));
  //   int need = 1;
  //   int j = i;
  //   while(j * 2 < K){
  //     need++;
  //     j *= 2;
  //   }
  //   ll p = pow(2,need);
  //   used.insert(p * 3);
  //   tmp[i-1] = p * 3;
  // }
  // ll b = 3;
  // repa(x,used) {
  //   if(x == 0){
  //     break;
  //   }
  //   b *= x;
  // }
  // long double a = 0;
  // repa(x,tmp) {
  //   a += b / x;
  // }
  // // cout << a << '\n';
  // // cout << b << '\n';
  // double res = a / b;
  // cout << fixed << setprecision(15) << res << '\n';

  int N,K;
  cin >> N >> K;
  double res = 0;
  rep(i,1,N+1) {
    int j = i;
    double q = 1.0 / N;
    while(j < K){
      j *= 2;
      q /= 2;
    }
    res += q;
  }
  cout << fixed << setprecision(15) << res << '\n';
  rt 0;
}
