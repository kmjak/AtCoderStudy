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
  int t = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
    if(a[i] <= 0){
      t++;
    }
  }
  if(n <= t+1){
    cout << 0 << endl;
    return 0;
  }
  int c = 0;
    sort(rall(a));
  while(true){
    a[0]--;
    a[1]--;
    c++;
    sort(rall(a));
    if(a[1] == 0){
      break;
    }
  }
  cout << c << endl;
  return 0;
}