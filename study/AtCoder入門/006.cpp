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
  int m = INT_MAX;
  rep(i,0,n){
    int a;
    int c = 0;
    cin >> a;
    while(m > c && a % 2 == 0){
      a /= 2;
      c++;
    }
    m = min(m, c);
  }
  cout << m << endl;
}