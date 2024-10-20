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


// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   ll i = 0;
//   ll sums = 0;
//   ll prev_sums = 0;
//   ll n = 2;
//   ll index = 0;
//   ll prev_index = 0;
//   vector<pair<ll,ll>> t;
//   while(index <= 1e17){
//     index += (1LL << i);
//     sums = prev_sums + (n * (index - prev_index));
//     t.pb(mp(index+1,sums));
//     i++;
//     n++;
//     prev_index = index;
//     prev_sums = sums;
//   }
//   ll N;
//   cin >> N;
//   ll num;
//   ll ind;
//   int y = 2;
//   repa(x,t){
//     if(x.first >= N){
//       num = x.second;
//       ind = x.first;
//       break;
//     }
//     y++;
//   }
//   cout << num - ((ind - N) * y) << '\n';
//   return 0;
// }


// 他の人の解き方
unordered_map<ll, ll> m;
ll f(ll N) {
  if (N == 1) return 0;
  if (m.count(N)) return m[N];
  m[N] = f(N / 2) + f((N + 1) / 2) + N;
  return m[N];
}

int main() {
  ll n;
  cin >> n;
  cout << f(n) << endl;
  return 0;
}