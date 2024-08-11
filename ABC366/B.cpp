#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  // int n;
  // cin >> n;
  // vector<string> s(n);
  // int max_len = 0;
  
  // rep(i, 0, n) {
  //   cin >> s[i];
  //   max_len = max(max_len, (int)s[i].size());
  // }

  // vector<string> T(max_len, string(n, '*'));

  // rep(i, 0, n) {
  //   int len = s[i].size();
  //   rep(j, 0, len) {
  //     T[j][n-1-i] = s[i][j];
  //   }
  // }

  // rep(i, 0, max_len) {
  //   while (T[i].back() == '*') {
  //     T[i].pop_back();
  //   }
  // }

  // rep(i, 0, max_len) {
  //   cout << T[i] << endl;
  // }
  int n;
  cin >> n;
  vector<string> s(n);
  int max_len = 0;
  rep(i, 0, n) {
    cin >> s[i];
    max_len = max(max_len, (int)s[i].size());
  }
  rep(i,0,max_len){
    for(int j = n-1; j >= 0; j--){
      if(i < s[j].size()){
        cout << s[j][i];
      }else{
        bool flag = false;
        for(int k = j-1; k > -1; k--){
          if(s[k].size() > i){
            flag = true;
            break;
          }
        }
        if(flag){
          cout << '*';
        }else{
          cout << ' ';
        }
      }
    }
    cout << endl;
  }
  return 0;
}