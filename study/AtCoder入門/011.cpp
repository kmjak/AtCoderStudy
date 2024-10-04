#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>

using namespace std;


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

  int n,y;
  cin >> n >> y;
  y /= 1000;

  rep(i,0,n+1){
    rep(j,0,n-i+1){
      if((i * 9 + j * 4 + n) == y){
        cout << i << " " << j << " " << n - j - i << endl;
        return 0;
      }else if ((i * 9 + j * 4 + n) > y) break;
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}