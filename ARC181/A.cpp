#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    vi cases(n);
    rep(i,0,n){
      cin >> cases[i];
    }
    vi goal = cases;
    sort(goal.begin(), goal.end());
    int c = 0;
    for(int k = 2; goal != cases; k++){
      sort(cases.begin(), cases.begin() + k - 1);
      if(k <= n -1){
        sort(cases.begin() + k + 1, cases.end());
      }
      if(goal == cases){
        break;
      }
      c++;
    }
    cout << c << endl;
  }
  return 0;
}