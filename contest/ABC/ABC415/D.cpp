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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,M;cin>>N>>M;
  vll A(M),B(M);
  vector<pair<ll,pair<ll,ll>>> scores(M);
  for(ll i=0;i<M;i++) cin>>A[i]>>B[i];
  for(ll i=0;i<M;i++)scores[i]=mp(A[i]-B[i], mp(A[i], B[i]));
  sort(all(scores));

  ll res=0;
  for(auto [diff, p]: scores){
    ll a=p.first;
    ll b=p.second;
    if(a>N)continue;
    ll cnt=(N-a)/diff+1;
    res+=cnt;
    N-=cnt*diff;
  }
  cout<<res<<endl;
  return 0;
}