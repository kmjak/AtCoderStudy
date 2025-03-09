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
#define tob(b) static_cast<int>(b.to_ulong())

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
  int N;
  cin >> N;
  int MAX = 1520;
  vvi Grid(MAX,vi(MAX,0));
  while(N--){
    pnt left,right;
    cin >> left.x >> left.y >> right.x >> right.y;
    Grid[left.y][left.x]++;
    Grid[left.y][right.x]--;
    Grid[right.y][left.x]--;
    Grid[right.y][right.x]++;
  }

  rep(i,0,MAX) {
    rep(j,0,MAX-1) {
      Grid[i][j+1] += Grid[i][j];
    }
  }

  rep(i,0,MAX) {
    rep(j,0,MAX-1) {
      Grid[j+1][i] += Grid[j][i];
    }
  }
  int res = 0;

  rep(i,0,MAX) {
    rep(j,0,MAX) {
      // cout << Grid[i][j] << ' ';
      if(Grid[i][j] != 0){
        res++;
      }
    }
    // END;
  }

  cout << res << '\n';
  return 0;
}