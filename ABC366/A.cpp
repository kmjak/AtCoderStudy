#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int n,t,c;
  cin >> n >> t >> c;
  n = (n + 1) / 2;
  if(max(t,c) >= n)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}