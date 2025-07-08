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
  ll N;cin>>N;
  vll F(N+1),S(N+1);
  for(ll i=0;i<N;i++){
    ll c,p;cin>>c>>p;
    F[i+1]+=F[i];
    S[i+1]+=S[i];
    if(c==1)F[i+1]+=p;
    else S[i+1]+=p;
  }

  ll Q;cin>>Q;
  while(Q--){
    ll l,r;cin>>l>>r;
    ll f=F[r]-F[l-1];
    ll s=S[r]-S[l-1];
    cout << f << " " << s << endl;
  }
  return 0;
}