#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

using ll=long long int;
using pi=pair<int,int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;

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

ll hamburger(int N, ll X,const vll &L, const vll &S){
  if(N==0) return 1;

  if(X==1)return 0;
  else if(X<=L[N-1] + 1) return hamburger(N-1,X-1,L,S);
  else if(X == L[N-1] + 2) return S[N-1] + 1;
  else if(X <= L[N-1] * 2 + 2) return hamburger(N-1,X-L[N-1]-2,L,S) + S[N-1] + 1;
  else return S[N-1] * 2 + 1;
}

int main()
{
  // 4割ほど理解できた
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,X;
  cin >> N >> X;
  vll L(N+1,1), S(N+1,1);
  rep(i,1,N+1){
    L[i] = L[i-1] * 2 + 3;
    S[i] = S[i-1] * 2 + 1;
  }

  cout << hamburger(N,X,L,S) << endl;
  return 0;
}