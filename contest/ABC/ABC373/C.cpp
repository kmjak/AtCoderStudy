#include <bits/stdc++.h>

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define vvs vector<vs>
#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define repra(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a_max = INT_MIN;
  int b_max = INT_MIN;
  rep(i, 0, n){
    int a;
    cin >> a;
    a_max = max(a_max, a);
  }
  rep(i, 0, n){
    int b;
    cin >> b;
    b_max = max(b_max, b);
  }
  cout << a_max + b_max << endl;
  return 0;
}