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
  ll N,A;
  cin>>A>>N;

  vs S;
  for(ll i=1;i<=1e6;i++){
    S.eb(tos(i));
  }

  vs X;
  for(ll i=0;i<=9;i++)X.eb(tos(i));
  for(auto s: S){
    string rs = s;
    reverse(all(rs));
    X.eb(s+rs);
    for(char i='0';i<='9';i++){
      X.eb(s+i+rs);
    }
  }

  ll res=0;
  for(auto x: X){
    ll n=stoll(x);
    if(n>N) continue;
    string t="";
    while(n>0){
      t+=toc(n%A);
      n/=A;
    }
    bool ok=true;
    reverse(all(t));
    ll k=t.size();
    for(ll i=0;i<k/2;i++){
      if(t[i]!=t[k-1-i]){
        ok=false;
        break;
      }
    }
    if(!ok) continue;
    res+=stoll(x);
  }
  cout<<res<<endl;
  return 0;
}
