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
#define toi(s) stoi(s)

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(N,A) for(int i = 0; i < N; i++) cin >> A[i];
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

#define sort(x) sort(all(x))
#define rsort(x) sort(rall(x))

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

int dist (int a, int b)
{
  return (a-b) * (a-b);
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,D;
  cin >> N >> D;
  vvi field(N,vi(D));
  rep(i,0,N) {
    rep(j,0,D) {
      cin >> field[i][j];
    }
  }
  int res = 0;
  rep(i,0,N-1) {
    rep(j,i+1,N) {
      int dis = 0;
      rep(k,0,D) {
        dis += dist(field[i][k],field[j][k]);
      }
      double flt = sqrt(dis);
      int num = flt;
      if(flt == num){
        res++;
      }
    }
  }
  cout << res << '\n';
  return 0;
}