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
  vi H(n,0);
  cin >> H[0];
  rep(i,0,n-1){
    int ans = 0;
    int max = H[i+1];
    rep(j,i+1,n){
      if(H[j] == 0){
        cin >> H[j];
      }
      if(H[j] >= max){
        ans++;
        max = H[j];
      }
    }
    cout << ans << " ";
  }
  cout << 0 << endl;
  return 0;
}