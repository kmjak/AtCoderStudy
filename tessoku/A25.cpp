#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H,W;
vector<string> G(40);
vector<vector<long long>> dp(40,vector<long long> (40,0));

int main()
{
  cin>>H>>W;
  for(int i=0;i<H;i++)cin>>G[i];
  for(int i=1;i<=H;i++){
    if(G[i-1][0]!='.')break;
    dp[i][1]=1;
  }
  for(int i=1;i<=W;i++){
    if(G[0][i-1]!='.')break;
    dp[1][i]=1;
  }
  for(int i=2;i<=H;i++){
    for(int j=2;j<=W;j++){
      if(G[i-1][j-1]=='.'){
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
      }
    }
  }
  // for(int i=0;i<=H;i++){
    // for(int j=0;j<=W;j++){
      // cout<<dp[i][j]<<" ";
    // }
    // cout<<endl;
  // }
  cout<<dp[H][W]<<endl;
}
