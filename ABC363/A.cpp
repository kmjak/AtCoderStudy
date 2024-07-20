#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int n;
  cin >> n;
  if(n <= 99){
    cout << 100 - n;
  }else if(n <= 199){
    cout << 200 - n;
  }else if(n <= 299){
    cout << 300 - n;
  }else if(n <= 399){
    cout << 400 - n;
  }
  return 0;
}