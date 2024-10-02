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
  string s;
  cin >> s;
  bool isC = false;
  rep(i,0,s.size()){
    if(i == 0){
      if(s[i] != 'A'){
        cout << "WA" << endl;
        return 0;
      }
      continue;
    }else{
      if(s[i] == 'C' && (i == 1 || i == s.size() - 1)){
        cout << "WA" << endl;
        return 0;
      }
      if(s[i] == 'C'){
        if(isC){
          cout << "WA" << endl;
          return 0;
        }
        isC = true;
        continue;
      }else{
        if(isupper(s[i])){
          cout << "WA" << endl;
          return 0;
        }
      }
    }
  }
  if(isC){
    cout << "AC" << endl;
  }else{
    cout << "WA" << endl;
  }
  return 0;
}