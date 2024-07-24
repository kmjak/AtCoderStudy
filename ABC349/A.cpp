#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vi a(n-1);
  rep(i,0,n-1) cin >> a[i];
  int sum = accumulate(a.begin(), a.end(), 0);
  cout << -sum << endl;
  return 0;
}