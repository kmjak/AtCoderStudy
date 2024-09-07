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
  vvi a(n,vi (n));
  rep(i,0,n){
    rep(j,0,i+1){
      cin >> a[i][j];
    }
  }
  int now = a[0][0];
  rep(i,1,n){
    if(i >= now){
      now = a[i][now-1];
    }else{
      now = a[now-1][i];
    }
  }
  cout << now << endl;
  return 0;
}