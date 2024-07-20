#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  ll n;
  cin >> n;
  ll c = 0;
  ll i = 0;
  // while(true){
  //   string temp = to_string(i);
  //   int l = temp.size();
  //   bool flag = true;
  //   for(int j = 0; j < (l/2); j++){
  //     if(temp[j] != temp[l - j - 1]){
  //       flag = false;
  //       break;
  //     }
  //   }
  //   if(flag){
  //     c++;
  //   }
  //   if(c == n){
  //     cout << i << endl;
  //     return 0;
  //   }
  //   i++;
  // }
  while(true){
    string temp = to_string(i);
    int l = temp.size();
    bool flag = true;
    for(int j = 0; j < l / 2; j++){
      if(temp[j] != temp[l - j - 1]){
        flag = false;
        break;
      }
    }
    bool addi = true;
    if(flag){
      cout << c << endl;
      if(n >= c + pow(10,l-1)){
        c += pow(10,l-1);
        i += pow(10,l-1);
        addi = false;
      }else{
        for(int j = l - 1; j > 0; j--){
          if(n >= c + pow(10,j-1)){
            c += pow(10,j-1);
            i += pow(10,j-1);
            addi = false;
          }
        }
      }
    }
    if(c == n){
      cout << i << endl;
      return 0;
    }
    if(addi){
      i++;
    }
  }
}