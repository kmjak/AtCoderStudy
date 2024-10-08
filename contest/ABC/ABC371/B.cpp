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
  int n,m;
  cin >> n >> m;
  vi used(n,0);
  rep(i,0,m){
    int a;
    char b;
    cin >> a >> b;
    if(b == 'M' && used[a-1] == 0){
      cout << "Yes" << endl;
      used[a-1] = 1;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}