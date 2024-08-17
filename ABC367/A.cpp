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

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if(c < b){
    a += 24;
    c += 24;
  }
  if(b < a && a < c){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }

  return 0;
}