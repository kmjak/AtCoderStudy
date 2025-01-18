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
  int H,W,N;
  cin >> H >> W >> N;
  vvi Grid(H+1,vi(W+1,0));
  while(N--){
    pnt s,g;
    cin >> s.y >> s.x >> g.y >> g.x;
    s.x--;
    s.y--;
    Grid[s.y][s.x]++;
    Grid[s.y][g.x]--;
    Grid[g.y][s.x]--;
    Grid[g.y][g.x]++;
  }


  rep(i,0,H) {
    rep(j,0,W-1) {
      Grid[i][j+1] += Grid[i][j];
    }
  }

  rep(i,0,W) {
    rep(j,0,H-1) {
      Grid[j+1][i] += Grid[j][i];
    }
  }

  rep(i,0,H) {
    rep(j,0,W) {
      cout << Grid[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}