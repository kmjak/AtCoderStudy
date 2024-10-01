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
  ll n,k;
  cin >> n >> k;
  vi x(n),a(n),b(n);
  rep(i,0,n) cin >> x[i];
  rep(i,0,n) cin >> a[i];
  rep(i,0,k){
    rep(i,0,n){
      b[i] = a[x[i]-1];
    };
    a = b;
  }
  rep(i,0,n) cout << a[i] << " ";
  cout << endl;
  return 0;
}