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
  int n;
  cin >> n;
  int l_prev  = -1;
  int r_prev  = -1;
  int ans = 0;

  rep(i,0,n){
    int a;
    char s;
    cin >> a >> s;
    if(s == 'L'){
      if(l_prev == -1){
        l_prev = a;
      }else{
        ans += abs(a - l_prev);
        l_prev = a;
      }
    }else{
      if(r_prev == -1){
        r_prev = a;
      }else{
        ans += abs(a - r_prev);
        r_prev = a;
      }
    }
  }
  cout << ans << endl;
  return 0;
}