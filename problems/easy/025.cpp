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
#define mt make_tuple
#define g(i,t) get<i>(t)
#define fi first
#define se second

#define tos(n) to_string(n)
#define toi(s) stoi(s)

#define NO cout << "No" << endl;
#define YES cout << "Yes" << endl;

#define vcin(N,A) rep(i,0,N) cin >> A[i];

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;

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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vi P(N),Q(N),Ptr(N);
  iota(all(Ptr),1);
  vcin(N,P);
  vcin(N,Q);
  ll p_i = 0;
  ll q_i = 0;
  ll j = 0;
  do
  {
    bool fq=true;
    bool fp=true;
    rep(i,0,N){
      if(P[i] != Ptr[i]){
        fp=false;
      }
      if(Q[i] != Ptr[i]){
        fq=false;
      }
    }
    if(fp){
      p_i = j;
    }
    if(fq){
      q_i = j;
    }
    if(p_i && q_i) break;
    j++;
  } while (next_permutation(all(Ptr)));

  cout << abs(p_i - q_i) << '\n';
  return 0;
}