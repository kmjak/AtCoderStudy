#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vint vector<int>
#define vvi vector<vector<int>>
#define vvi vector<vector<int>>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int n,m,t;
  cin >> n >> m >> t;
  int c = 2 * n * (n - 1);

  vvi seeds(c, vi(m));
  rep(i,0,c){
    rep(j,0,m){
      cin >> seeds[i][j];
    }
  }
  rep(i,0,t){
    rep(j,0,n){
      rep(k,0,n){
        cout << j * n + k << " ";
      }
      cout << endl;
    }
  }
  // vi seeds(c * m);
  // rep(i,0,c * m){
  //   cin >> seeds[i];
  // }
  // rep(i,0,t){
  //   sort(seeds.begin(), seeds.end(), greater<int>());
  //   int temp = 0;
  //   rep(j,0,n){
  //     rep(k,0,n){
  //       if((j == 0 || j == n - 1) && (k == 0 || k == n - 1)){
  //         cout << seeds[temp] << " ";
  //         temp++;
  //       }
  //       else{
  //         cout << seeds.back() << " ";
  //         seeds.pop_back();
  //       }
  //     }
  //     cout << endl;
  //   }
  //   rep(j,0,c){
  //     rep(k,0,m){
  //       cin >> seeds[j * m + k];
  //     }
  //   }
  // }
  return 0;
}