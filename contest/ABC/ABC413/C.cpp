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
#define btoi(b) static_cast<int>(b.to_ulong())

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

struct pnt {
  ll x;
  ll y;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<pair<ll,ll>> A;
  ll Q;
  cin>>Q;
  ll cur=0;
  while(Q--){
    ll opt;cin>>opt;
    if(opt==1){
      ll c,x;
      cin>>c>>x;
      A.eb(c,x);
    }else{
      ll k;
      ll res=0;
      cin>>k;
      while(true){
        pair<ll,ll> p=A[cur];
        if(p.first>=k){
          res+=k*p.second;
          A[cur].first-=k;
          break;
        }
        res+=p.first*p.second;
        k-=p.first;
        cur++;
      }
      cout<<res<<endl;
    }
  }
  return 0;
}