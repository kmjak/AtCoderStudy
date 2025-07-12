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
  ll N,P,Q;cin >> N >> P >> Q;
  vll A(N);
  for(ll i=0;i<N;i++) cin >> A[i];

  ll res=0;
  for(ll i=0;i<N;i++){
    for(ll j=i+1;j<N;j++){
      for(ll k=j+1;k<N;k++){
        for(ll l=k+1;l<N;l++){
          for(ll m=l+1;m<N;m++){
            ll score=(A[i]*A[j])%P;
            score=(score*A[k])%P;
            score=(score*A[l])%P;
            score=(score*A[m])%P;
            if(score==Q) res++;
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}