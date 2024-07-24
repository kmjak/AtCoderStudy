#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  string s;
  cin >> s;
  map<char, int> m;
  for(auto x : s){
    if(m.find(x) == m.end()) {
      m[x] = 1;
    } else{
      m[x]++;
    }
  }
  map<int, int> n;
  for(auto x : m){
    if(n.find(x.second) == n.end()){
      n[x.second] = 1;
    } else{
      n[x.second]++;
    }
  }
  for(auto it = n.begin(); it != n.end(); ++it) {
    if(it->second != 0 && it->second != 2){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
