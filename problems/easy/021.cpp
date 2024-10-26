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

#define tos(n) to_string(n)
#define toi(s) stoi(s)

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
vll prime;

bool isPrime(ll n)
{
  repa(x,prime){
    if(n%x==0){
      return false;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N;
  cin >> N;
  ll num = 6;
  if(N != 2) prime.pb(2);
  if(N > 3)prime.pb(3);
  while(num < N){
    if(isPrime(num-1)){
      prime.pb(num-1);
    }
    if(isPrime(num+1) && num+1 != N){
      prime.pb(num+1);
    }
    num += 6;
  }
  ll res = N;
  while(true){
    if(isPrime(res)){
      break;
    }
    if(res%2==0) res++;
    else res += 2;
  }
  cout << res << '\n';
  return 0;
}