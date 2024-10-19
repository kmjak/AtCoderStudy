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
  vi A(N),B(N-1);
  rep(i,0,N) cin >> A[i];
  rep(i,0,N-1) cin >> B[i];
  sort(all(A));
  sort(all(B));
  int MAX_B = B.back();
  int over = 0;
  rep(i,0,N){
    if(A[i] >= MAX_B){
      over = N - i - 1;
      break;
    }
  }
  bool is_over = false;
  int res = 0;
  int j = N-2;
  rrep(i,N-1,-1){
    if(A[i] > B[j]){
      if(is_over){
        cout << -1 << endl;
        return 0;
      }
      res = A[i];
      is_over = true;
      j++;
    }
    j--;
  }
  if(!is_over){
    res = A[0];
  }
  cout << res << endl;
  return 0;
}