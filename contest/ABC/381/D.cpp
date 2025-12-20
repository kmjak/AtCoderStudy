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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N;
  cin >> N;
  vi A(N);
  vcin(N, A);
  int res = 0;
  rep(s, 0, N) {
    unordered_map<int, int> M;
    vi current;
    
    rep(end, s, N) {
      M[A[end]]++;
      current.pb(A[end]);
      
      while (any_of(all(M), [](const auto& p) { return p.second > 2; })) {
        M[current.front()]--;
        current.erase(current.begin());
      }
      
      if (current.size() % 2 == 0) {
        bool flag = true;
        for (int i = 0; i < current.size(); i += 2) {
          if (current[i] != current[i+1]) {
            flag = false;
            break;
          }
        }
        
        if (flag) {
          res = max(res, (int)current.size());
        }
      }
    }
  }
  
  cout << res << '\n';
  return 0;
}