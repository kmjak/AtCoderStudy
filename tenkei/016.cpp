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

struct pnt {
  ll x;
  ll y;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N;
  vll C(3);
  cin>>N;
  vll res;
  for(ll i=0;i<3;i++)cin>>C[i];
  for(ll i=0;i<10000;i++){
    for(ll j=0;j<10000-i;j++){
      ll rest=N-C[0]*i - C[1]*j;
      if(rest<0)break;
      if(rest%C[2]==0){
        ll l = rest / C[2];
        res.eb(i+j+l);
      }
    }
  }
  sort(all(res));
  cout<<res[0]<<endl;
  return 0;
}