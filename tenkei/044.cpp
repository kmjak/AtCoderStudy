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
using pll=pair<ll,ll>;
using qll=queue<ll>;
using qp=queue<pll>;
using sll=set<ll>;

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,Q;cin>>N>>Q;
  vll A(N);
  for(ll i=0;i<N;i++)cin>>A[i];

  ll cur=N;
  while(Q--){
    ll t,x,y;cin>>t>>x>>y;
    x--;y--;
    if(t==1){
      swap(A[(x+cur)%N], A[(y+cur)%N]);
    }else if(t==2){
      cur--;
      if(cur<0) cur=N;
    }else{
      cout<<A[(x+cur)%N]<<endl;
    }
    // cout <<"P: ";
    // for(int i=0;i<N;i++) {
    //   cout << A[(i+cur)%N] << " ";
    // }
    // cout << endl;
  }
  return 0;
}