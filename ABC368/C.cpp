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
  ll h;
  ll t = 0;
  rep(i, 0, n)
  {
    cin >> h;
    if(t % 3 == 1){
      t++;
      h--;
    }
    if(t % 3 == 2 && h >= 1){
      t++;
      h -= 3;
    }
    if(h >= 1){
      t += (h / 5) * 3;
      h %= 5;
      if(h == 1 || h == 2){
        t += h;
      }else if(h == 3 || h == 4){
        t += 3;
      }
    }
  }
  std::cout << t << endl;
  return 0;
}