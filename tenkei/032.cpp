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
  vvll A(N,vll(N));
  for(ll i=0;i<N;i++)for(ll j=0;j<N;j++)cin>>A[i][j];
  ll M;cin>>M;
  set<pll> B;
  for(ll i=0;i<M;i++){
    ll x,y;cin>>x>>y;
    x--;y--;
    B.insert(mp(x,y));
    B.insert(mp(y,x));
  }
  vll P(N);
  iota(all(P), 0LL);

  ll res=LLONG_MAX;
  do{
    bool ok = true;
    for(ll i=0;i<N-1;i++){
      if(B.count(mp(P[i],P[i+1]))){
        ok = false;
        break;
      }
    }
    if(ok==false)continue;
    // cout<<"P: ";
    // for(ll i=0;i<N;i++)cout<<P[i]<<" ";
    // cout<<endl;

    ll score=0;
    for(ll i=0;i<N;i++){
      score+=A[P[i]][i];
    }
    // cout<<"score: "<<score<<endl;
    chmin(res, score);
  }while(next_permutation(all(P)));
  cout<<(res==LLONG_MAX?-1:res)<<endl;

  return 0;
}