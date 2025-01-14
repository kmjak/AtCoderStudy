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

struct pnt {
  ll x;
  ll y;
};

ll snake(int k, int x)
{
  if(x == 1){
    return 1;
  }
  return pow(x,k-1) + snake(k,x-1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // ll L,R;
  // cin >> L >> R;
  // ll snake = 0;
  // rep(i,L,R+1){
  //   int t = toi(tos(i).substr(0, 1));
  //   int j = 1;
  //   bool c = true;
  //   while(tos(i).size() > j) {
  //     if(t <= toi(tos(i).substr(j, 1))){
  //       c = false;
  //       break;
  //     }
  //     j++;
  //   }
  //   if(c){
  //     snake++;
  //   }
  // }
  // cout << snake << '\n';
  //

  // X^(K-1);
  ll L,R;
  cin >> L >> R;
  ll res = 0;
  return 0;
}