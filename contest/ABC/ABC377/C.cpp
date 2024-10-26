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

#define tos(n) to_string(n)
#define toi(s) stoi(s)

#define NO cout << "No" << endl;
#define YES cout << "Yes" << endl;

#define vcin(N,A) rep(i,0,N) cin >> A[i];
#define vcout(X) repa(x,X) cout << x << ' ';

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

vi dx = {2,1,2,1,-2,-1,-2,-1};
vi dy = {1,2,-1,-2,1,2,-1,-2};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,M;
  cin >> N >> M;
  set<pi> impossible;
  rep(i,0,M){
    ll x,y;
    cin >> x >> y;
    x--; y--;
    impossible.insert(mp(x,y));
    rep(j,0,8){
      ll nx = x + dx[j];
      ll ny = y + dy[j];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      impossible.insert(mp(nx,ny));
    }
  }
  cout << N * N - impossible.size() << '\n';
  return 0;
}