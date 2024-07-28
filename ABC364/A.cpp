#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,0,n) cin >> s[i];
  rep(i,0,n-1){
    if(s[i] == "sweet" && s[i+1] == "sweet"){
      if(i + 1 != n - 1){
        cout << "No" << endl;
        return 0;
      }
      cout << "Yes";
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}