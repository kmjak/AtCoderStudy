#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
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
  ll N,Q;
  cin>>N>>Q;
  vll A(N);
  vll diff(N+2);
  for(ll i=0;i<N;i++)cin>>A[i];
  ll res=0;
  for(ll i=0;i<N-1;i++){
    diff[i+1]=A[i+1]-A[i];
    res+=abs(diff[i+1]);
  }

  while(Q--){
    ll l,r,v;cin>>l>>r>>v;
    ll prev=abs(diff[l-1])+abs(diff[r]);
    if(l>=2)diff[l-1]+=v;
    if(r<=N-1)diff[r]-=v;
    ll nx=abs(diff[l-1])+abs(diff[r]);
    res+=nx-prev;
    cout<<res<<endl;
  }
  return 0;
}