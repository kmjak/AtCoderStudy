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
  int n,MG,MH;
  cin >> n >> MG;

  vi u(MG),v(MG);
  rep(i,0,MG){
    cin >> u[i] >> v[i];
  }

  cin >> MH;
  vi a(MH),b(MH);

  rep(i,0,MH){
    cin >> a[i] >> b[i];
  }

  return 0;
}