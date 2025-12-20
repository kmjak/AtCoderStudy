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
  int l,r;
  cin >> l >> r;
  if(l == r){
    cout << "Invalid";
  }else if(l == 1){
    cout << "Yes";
  }else if(r == 1){
    cout << "No";
  }
  cout << endl;
  return 0;
}