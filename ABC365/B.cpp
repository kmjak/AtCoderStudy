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
  vi a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  vi temp = a;
  sort(rall(temp));
  rep(i, 0, n)
  {
    if (a[i] == temp[1])
    {
      cout << i+1 << endl;
      return 0;
    }
  }
  return 0;
}