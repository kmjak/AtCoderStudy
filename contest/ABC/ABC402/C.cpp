#include <bits/stdc++.h>

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
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);
  int N, M;
  cin >> N >> M;
  vvi ignore(N + 1);
  vvi D(M);
  vi B(N);
  vi cnt(M);
  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    D[i].resize(k);
    for (int j=0;j<k;j++) {
      cin >> D[i][j];
      ignore[D[i][j]].eb(i);
    }
    cnt[i] = k;
  }
  for (int i = 0; i < N; i++) cin >> B[i];
  int res = 0;
  vb used(M,false);
  for (int i = 0; i < N; i++) {
    int j = B[i];
    for (int d : ignore[j]) {
      cnt[d]--;
      if (cnt[d]==0&& !used[d]) {
        used[d]=true;
        res++;
      }
    }
    cout << res << endl;
  }

  return 0;
}