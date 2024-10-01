#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int r,g,b;
  string c;
  cin >> r >> g >> b >> c;
  if(c == "Red"){
    cout << min(b,g) << endl;
  }
  else if(c == "Blue"){
    cout << min(r,g) << endl;
  }
  else{
    cout << min(r,b) << endl;
  }
  return 0;
}