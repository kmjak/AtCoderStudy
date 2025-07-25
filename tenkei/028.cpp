#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toll(s) stoll(s)
#define btoi(b) static_cast<ll>(b.to_ulong())

using namespace std;

using ll=long long int;
using qll=queue<ll>;
using dq=deque<ll>;

using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;
vvll G(1010, vll(1010));

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N;cin>>N;
  for(ll i=0;i<N;i++){
    ll lx,ly,rx,ry;cin>>lx>>ly>>rx>>ry;
    G[ly][lx]++;
    G[ry][lx]--;
    G[ly][rx]--;
    G[ry][rx]++;
  }
  for(ll i=0;i<1010;i++){
    for(ll j=1;j<1010;j++){
      G[j][i]+=G[j-1][i];
    }
  }

  for(ll i=0;i<1010;i++){
    for(ll j=1;j<1010;j++){
      G[i][j]+=G[i][j-1];
    }
  }

  vll res(N+1);
  for(ll i=0;i<1010;i++){
    for(ll j=0;j<1010;j++){
      res[G[i][j]]++;
    }
  }

  for(ll i=1;i<=N;i++)cout<<res[i]<<endl;
  return 0;
}