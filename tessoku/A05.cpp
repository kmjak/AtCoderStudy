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
  int n,k;
  int c = 0;
  cin >> n >> k;
  rep(i,1,n+1){
    rep(j,1,n+1){
      if(k - (i + j) <= n && k - (i + j) > 0){
        c++;
      }
    }
  }
  cout << c << endl;
}