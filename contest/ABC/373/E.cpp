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
  int n,m,k;
  cin >> n >> m >> k;
  m--;
  int total = 0;
  vector<pair<ll,int>> a(n);
  rep(i, 0, n){
    int x;
    cin >> x;
    a[i] = {x, i};
    total += x;
  }
  sort(all(a));

  rep(i,0,n){
    int l = 1;
    int possible = k-total;
    int my = a[i].first;
    while(possible){
      if(n - m - l > i){
        int target = a[n-m-l].first;
        if((target - my) * (l+1) <= possible){
          my = target;
          possible -= target - my;
          l++;
        }else{
          my += possible / (l+1);
          if(possible % (l+1) != 0) my++;
          possible = 0;
        }
      }else{
        
      }
    }
    cout << my << " ";
  }
  return 0;
}