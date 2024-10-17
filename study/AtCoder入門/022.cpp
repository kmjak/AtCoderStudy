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

int N, M,Q;
vll a,b,c,d;

ll calc_score(const vi& A)
{
  ll score = 0;
  rep(q,0,Q){
    if(A[b[q]] - A[a[q]] == c[q]) score += d[q];
  }
  return score;
}

ll rec(vi& A){
  if(A.size() == N)return calc_score(A);

  ll res = 0;

  int prev_last = (A.empty() ? 1 : A.back());

  rep(add,prev_last,M+1){
    A.pb(add);

    chmax(res,rec(A));

    A.pop_back();
  }
  return res;
}

int main()
{
  // 問題の意味すらわからなかった
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> Q;
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);

  rep(i,0,Q){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--;
    b[i]--;
  }

  vi A;
  cout << rec(A) << endl;

  return 0;
}