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
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  x /= 50;
  int counter = 0;
  rep(i,0,a+1){
    rep(j,0,b+1){
      rep(k,0,c+1){
        if(i * 10 + j * 2 + k == x){
          counter++;
          break;
        }else if(i * 10 + j * 2 + k > x){
          break;
        }
      }
    }
  }
  cout << counter << endl;
  return 0;
}