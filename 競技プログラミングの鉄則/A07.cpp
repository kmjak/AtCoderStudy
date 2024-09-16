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
  int d,n;
  cin >> d >> n;
  vi t(d);
  rep(i,0,n){
    int l,r;
    cin >> l >> r;
    rep(j,l,r+1){
      t[j-1]++;
    }
  }
  repa(i,t){
    cout << i << endl;
  }
  return 0;
}