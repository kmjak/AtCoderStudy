#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
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
  // int N,Q;
  // cin >> N >> Q;
  // string S;
  // cin >> S;
  // vi R(N+1,0);
  // rep(i,1,N){
  //   R[i+1] = R[i];
  //   if(S[i-1] == 'A' && S[i] == 'C'){
  //     R[i+1]++;
  //   }
  // }
  // while(Q--){
  //   int l,r;
  //   cin >> l >> r;
  //   int res = R[r] - R[l];
  //   cout << res << endl;
  // }

  int N,Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vi cs(N+1,0);
  rep(i,1,N){
    cs[i + 1] = cs[i] + (S.substr(i-1,2) == "AC");
  }

  rep(q,0,Q){
    int l,r;
    cin >> l >> r;
    cout << cs[r] - cs[l] << endl;
  }

  return 0;
}