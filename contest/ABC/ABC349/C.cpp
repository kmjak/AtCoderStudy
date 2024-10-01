#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  string s,t;
  cin >> s >> t;
  for(auto x : t){
    if(x == 'X'){
      continue;
    }
    if(s.find(tolower(x)) == string::npos){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}