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

vll dx={0, 0, 1, 1};
vll dy={0, 1, 0, 1};
const ll MOD=1e9+7;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll H,W;cin>>H>>W;
  vvll A(H, vll(W)), B(H, vll(W));
  for(ll i=0;i<H;i++)for(ll j=0;j<W;j++)cin>>A[i][j];
  for(ll i=0;i<H;i++)for(ll j=0;j<W;j++)cin>>B[i][j];

  ll res=0;
  for(ll i=0;i<H-1;i++){
    for(ll j=0;j<W-1;j++){
      ll diff=B[i][j]-A[i][j];
      res+=abs(diff);
      for(ll k=0;k<4;k++){
        ll ny=i+dy[k];
        ll nx=j+dx[k];
        A[ny][nx]+=diff;
      }
    }
  }
  if(A==B) {
    cout<<"Yes"<<endl;
    cout<<res<<endl;
  } else {
    cout<<"No"<<endl;
  }
  return 0;
}