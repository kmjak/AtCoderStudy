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
  int n,m,c=0;
  cin >> n >> m;
  vll a(n);
  rep(i,0,n){
    cin >> a[i];
  }
  ll total = 0;
  rep(i,0,n){
    total = 0;
    rep(j,1,n){
      total += a[(i + j) % n];
      if (total % m == 0) c++;
    }
  }
  cout << c << endl;
}