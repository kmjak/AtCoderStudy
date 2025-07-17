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
  ll N,L,K;
  cin>>N>>L>>K;
  vll diff(N+1);
  ll prev=0;
  for(ll i=0;i<N;i++){
    ll a;cin>>a;
    diff[i]=a-prev;
    prev=a;
  }
  diff[N]=L-prev;
  ll mx=L/K;
  ll res=0;
  ll l=0;
  ll r=mx+1;
  while(r-l>1){
    ll mid=(l+r)/2;
    ll cnt=0;
    ll sum=0;
    for(ll j=0;j<=N;j++){
      sum+=diff[j];
      if(sum>=mid){
        cnt++;
        sum=0;
      }
    }
    if(cnt>K){
      chmax(res,mid);
      l=mid;
    }else{
      r=mid;
    }
  }
  cout<<res<<endl;
  return 0;
}