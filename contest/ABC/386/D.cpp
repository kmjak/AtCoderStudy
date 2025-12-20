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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,M;
  cin >> N >> M;
  // vll B_x(N,-1),B_y(N,-1),W_x(N,N),W_y(N,N);
  unordered_map<ll, ll> B_x, B_y, W_x, W_y;
  rep(i,0,N) {
    B_x[i] = -1;
    B_y[i] = -1;
    W_x[i] = N;
    W_y[i] = N;
  }

  rep(i,0,M) {
    ll x,y;
    char c;
    cin >> y >> x >> c;
    x--;
    y--;
    if(c == 'B') {
      chmax(B_x[y],x);
      chmax(B_y[x],y);
    } else {
      chmin(W_x[y],x);
      chmin(W_y[x],y);
    }
  }
  rep(i,0,N-1) {
    chmax(B_x[N-i-2],B_x[N-i-1]);
    chmax(B_y[N-i-2],B_y[N-i-1]);
    chmin(W_x[i+1],W_x[i]);
    chmin(W_y[i+1],W_y[i]);
  }
  bool check = true;
  rep(i,0,N) {
    cout << B_x[i] << " " << W_x[i] << '\n';
    cout << B_y[i] << " " << W_y[i] << '\n';
    if(B_x[i] >= W_x[i] || B_y[i] >= W_y[i]) {
      check = false;
      break;
    }
  }
  // bool check = true;

  // repa(x, B_x) {
  //   if(x.second >= W_x[x.first]) {
  //     check = false;
  //     break;
  //   }
  // }
  // cout << check << '\n';

  // repa(y, B_y) {
  //   if(y.second >= W_y[y.first]) {
  //     check = false;
  //     break;
  //   }
  // }
  // cout << check << '\n';

  // repa(x, W_x) {
  //   if(x.second <= B_x[x.first]) {
  //     check = false;
  //     break;
  //   }
  // }
  // cout << check << '\n';

  // repa(y, W_y) {
  //   if(y.second <= B_y[y.first]) {
  //     check = false;
  //     break;
  //   }
  // }
  // cout << check << '\n';

  if(check) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}