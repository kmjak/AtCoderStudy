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

// int N,M;
// vs res;

// vi f(vvi &P, int k)
// {
//   vi tmp;
//   rep(i,1+(k * 10),M - (N - k - 1) * 10 + 1) {
//     tmp.pb(i);
//   }
//   return tmp;
// }

// void rec(vvi &A, vi &current, int k) {
//   if (k == N) {
//     string s = "";
//     bool flag = true;
//     int prev = -10;
//     repa(x,current){
//       s += tos(x) + " ";
//       if(prev + 10 > x){
//         flag = false;
//         break;
//       }
//       prev = x;
//     }
//     if(flag){
//       res.eb(s);
//     }
//     return;
//   }

//   rep (i,0,N) {
//     current[k] = A[k][i];
//     rec(A, current, k + 1);
//   }
// }

// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   cin >> N >> M;
//   vvi P(N);
//   vi current(N);
//   rep(i,0,N) {
//     P[i] = f(P,i);
//   }
//   rec(P, current, 0);

//   sort(all(res));
//   cout << res.size() << '\n';
//   repa(x,res){
//     cout << x << endl;
//   }
//   return 0;
// }

int N,M;
vs res;

int main ()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  vi P(N);
  rep(i,0,N) {
    P[i] = i * 10 + 1;
  }
  ll idx = N -1;
  vi sum(N,0);
  while(true){
    vi tmp = P;
    rep(i,0,N) {
      cout << tmp[i] + sum[i] << ' ';
    }
    cout << '\n';
    if(tmp[idx] + sum[idx] + 1 > M - (N - idx - 1) * 10){
      idx--;
    }else{
      sum[idx]++;
    }
    if(idx == -1){
      break;
    }
  }
}