#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int queries;
  cin >> queries;
  int q;
  map<int, int> action;
  rep(i, 0, queries) {
    cin >> q;
    if(q == 1) {
      int x;
      cin >> x;
      if(action.find(x) == action.end()) {
        action[x] = 1;
      }else{
        action[x]++;
      }
    }
    if(q == 2){
      int x;
      cin >> x;
      if(action[x] == 1){
        action.erase(x);
      }else{
        action[x]--;
      }
    }
    if(q == 3){
      cout << action.size() << endl;
    }
  }
  return 0;
}