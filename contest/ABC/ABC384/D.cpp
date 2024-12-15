#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define END cout << '\n'

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  ll S;
  cin >> N >> S;
  vll A(N+1,0);
  rep(i,0,N) {
    ll a;
    cin >> a;
    A[i+1] = A[i] + a;
  }
  S = S % A[N];
  if(S == 0) {
    YES;
    return 0;
  }
  rep(i,0,N) {
    int MIN = 0;
    int MAX = N;
    // cout << "-----------" << '\n';
    while(MAX - MIN > 1) {
      int MID = (MAX + MIN) / 2;
      // cout << A[MID] - A[i] << '\n';
      if(A[MID] - A[i] >= S) {
        MAX = MID;
      }else{
        MIN = MID;
      }
    }
    if(A[MAX] - A[i] == S) {
      YES;
      return 0;
    }
  }
  NO;
  return 0;
}