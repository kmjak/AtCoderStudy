#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define rrep(i,s,n) for(int i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vi a(n);
  rep(i, 0, n){
    cin >> a[i];
  }
  if(m >= accumulate(all(a), 0)){
    cout << "infinite" << endl;
    return 0;
  }
  int x = 1;
  int ans = 0;
  while(true){
    rep(i, 0, n){
      ans += min(x, a[i]);
      if(ans > m){
        cout << x << endl;
        return 0;
      }
    }
    x++;
  }
  return 0;
}