#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  // 10, 9, 9, 90, 90, 900, 900, 9000, 9000, 90000, 90000, 900000
  // int c = 0;
  // bool flag;
  // for(int i = 100000; i < 1000000; i++) {
  //   string temp = to_string(i);
  //   flag = true;
  //   for(int j = 0; j < temp.size()/2; j++) {
  //     if(temp[j] != temp[temp.size()-1-j]) {
  //       flag = false;
  //       break;
  //     }
  //   }
  //   if(flag) {
  //     cout << i << endl;
  //     c++;
  //   }
  // }
  // cout << c << endl;

  // ll i = 0;
  // bool flag;
  // while(true) {
  //   string temp = to_string(i);
  //   flag = true;
  //   rep(j,0,temp.size()) {
  //     if(temp[j] != temp[temp.size()-1-j]) {
  //       flag = false;
  //       break;
  //     }
  //   }
  //   if(flag) {
  //     if(temp.size() > 1 && n >= pow(10, temp.size() - 1)) {
  //       n -= pow(10, temp.size() - 2);
  //       int t = ((temp[0] - '0') + 1) * pow(10, temp.size() - 1);
  //       i = t;
  //     } else {
  //       n--;
  //     }
  //   }
  //   if(n == 0) {
  //     break;
  //   }
  //   i++;
  // }
  // cout << i << endl;
  ll n;
  cin >> n;
  ll m = 9;
  int i = 1;
  ll j = 1;
  n--;
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }

  while(true){
    if(n - m > 0){
      n -= m;
    }else{
      break;
    }
    if(i % 2 == 0){
      m *= 10;
    }
    j *= 10;
    i++;
  }


  bool flag;
  while(true) {
    string temp = to_string(j);
    flag = true;
    rep(k,0,temp.size()) {
      if(temp[k] != temp[temp.size()-1-k]) {
        flag = false;
        break;
      }
    }
    if(flag) {
      if(temp.size() > 1 && n >= pow(10, temp.size() - 1)) {
        n -= pow(10, temp.size() - 2);
        int t = ((temp[0] - '0') + 1) * pow(10, temp.size() - 1);
        j = t;
      } else {
        n--;
      }
    }
    if(n == 0) {
      break;
    }
    j++;
  }
  cout << j << endl;

  return 0;
}