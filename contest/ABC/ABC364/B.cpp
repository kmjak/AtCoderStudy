#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int H, W,S_x, S_y;
  cin >> H >> W >> S_x >> S_y;
  S_x--;
  S_y--;
  vector<vector<char>> c(H, vector<char>(W));
  rep(i,0,H){
    rep(j,0,W){
      cin >> c[i][j];
    }
  }
  string x;
  cin >> x;
  for(auto order : x){
    if(order == 'L'){
      if(S_y - 1 >= 0 && c[S_x][S_y-1] != '#'){
        S_y--;
      }
    }
    if(order == 'R'){
      if(S_y + 1 < W && c[S_x][S_y+1] != '#'){
        S_y++;
      }
    }
    if(order == 'U'){
      if(S_x - 1 >= 0 && c[S_x-1][S_y] != '#'){
        S_x--;
      }
    }
    if(order == 'D'){
      if(S_x + 1 < H && c[S_x+1][S_y] != '#'){
        S_x++;
      }
    }
  }
  cout << S_x + 1 << " " << S_y + 1<< endl;
  return 0;
}