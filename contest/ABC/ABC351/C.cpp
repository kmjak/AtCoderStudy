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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  vi Ball;
  rep(i, 0, N) {
    int x;
    cin >> x;
    Ball.pb(x);

    while (true) {
      int b_size = Ball.size();
      if (b_size <= 1) {
        break;
      }
      if (Ball[b_size-1] != Ball[b_size-2]) {
        break;
      }
      int tmp = Ball.back();
      Ball.pop_back();
      Ball.pop_back();
      Ball.pb(tmp + 1);
    }
  }
  cout << Ball.size() << endl;
  return 0;
}