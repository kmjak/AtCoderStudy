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
  vll a(n);
  rep(i, 0, n) cin >> a[i];
  int t = 0;
  ll p = 0;
  rep(i,0,n-2){
    if(t % 2 == 0){
      if(a[i] + a[i+1] * 2 + a[i+2] >= a[i+1] + a[i+2] * 2){
        p += a[i];
        t++;
      }
    }else{
      if(a[i] * 2 + a[i+1] + a[i+2] >= a[i+1] * 2 + a[i+2]){
        p += a[i];
        t++;
      }
    }
  }
  if(t % 2 == 0){
    p += a[n-2];
    p += a[n-1] * 2;
  }else{
    if(a[n-2] * 2 >= a[n-1]){
      p += a[n-2]*2;
      p += a[n-1];
    }else{
      p += a[n-1] * 2;
    }
  }
  cout << p << endl;

  return 0;
}