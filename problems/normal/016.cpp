#include <bits/stdc++.h>

#define rt return

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

// int main()
// {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
  // int N;
  // cin >> N;
  // vi S(N);
  // ll res = 0;
  // vcin(N,S);
  // ll totalScore = reduce(all(S),0);
  // if(totalScore % 10 != 0){
  //   cout << totalScore << '\n';
  //   rt 0;
  // }
  // for(int i = 0; i < (1<<N); i++){
  //   ll score = totalScore;
  //   rep(j,0,N) {
  //     if(1 & (i>>j)){
  //       score -= S[j];
  //     }
  //   }
  //   if(score % 10 != 0){
  //     chmax(res,score);
  //   }
  // }
  // cout << res << '\n';

//   int N;
//   cin >> N;
//   vi S(N);
//   vcin(N,S);
//   vb p(1e4+10,false);
//   p[0] = true;
//   for(int i = 0; i < (1<<N); i++){
//     ll sum = 0;
//     rep(j,0,N) {
//       if(1&(i>>j)){
//         sum += S[j];
//       }
//     }
//     if(sum % 10 == 0) {
//       continue;
//     }
//     p[sum] = true;
//   }
//   rrep(i,1e4+1,-1) {
//     if(p[i]){
//       cout << i << '\n';
//       rt 0;
//     }
//   }
//   rt 0;
// }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  int MIN = 0;
  ll sum = 0;
  rep(i,0,N) {
    int s;
    cin >> s;
    if(s % 10 != 0){
      if(MIN == 0){
        MIN = s;
      }
      chmin(MIN,s);
    }
    sum += s;
  }
  if(sum % 10 != 0){
    cout << sum << '\n';
  }else{
    if((sum - MIN) % 10 == 0){
      cout << 0 << '\n';
    }else{
      cout << sum - MIN << '\n';
    }
  }
  return 0;
}
