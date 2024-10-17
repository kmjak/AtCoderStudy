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
  string S;
  cin >> S;

  int N = S.size();

  vector<bool> dp(N+1,false);
  dp[0] = true;
  rep(i,1,N+1){
    if(i >= 5 && dp[i-5] && S.substr(i-5,5) == "erase"){
      dp[i] = true;
    }
    if(i >= 6 && dp[i-6] && S.substr(i-6,6) == "eraser"){
      dp[i] = true;
    }
    if(i >= 5 && dp[i-5] && S.substr(i-5,5) == "dream"){
      dp[i] = true;
    }
    if(i >= 7 && dp[i-7] && S.substr(i-7,7) == "dreamer"){
      dp[i] = true;
    }
  }

  if(dp[N]) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}