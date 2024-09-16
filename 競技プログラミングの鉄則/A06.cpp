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

int main(){
  int n,q;
  cin >> n >> q;
  vi sums(n+1,0);
  rep(i,1,n+1){
    int a;
    cin >> a;
    sums[i] = sums[i-1] + a;
  }
  vi ans(q);
  rep(i,0,q){
    int l,r;
    cin >> l >> r;
    ans[i] = sums[r] - sums[l-1];
  }
  repa(i,ans){
    cout << i << endl;
  }
}