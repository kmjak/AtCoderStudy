#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<vector<int>> A(110,vector<int>(20));
vector<vector<int>> dp(110,vector<int>(1100,110));
int main()
{
  cin>>N>>M;
  for(int i=1;i<=M;i++)for(int j=1;j<=N;j++)cin>>A[i][j];
  dp[0][0]=0;
  for(int i=1;i<=M;i++){
    for(int j=0;j<(1<<N);j++){
      vector<int> used(20);
      for(int k=1;k<=N;k++){
        if((1&(j>>(k-1)))==0)used[k]=0;
        else used[k]=1;
      }
      int v=0;
      for(int k=1;k<=N;k++){
        if(used[k]==1||A[i][k]==1)v+=(1<<(k-1));
      }
      dp[i][j]=min(dp[i][j],dp[i-1][j]);
      dp[i][v]=min(dp[i][v],dp[i-1][j]+1);
    }
  }
  if(dp[M][(1<<N)-1]==110)cout<<-1<<endl;
  else cout<<dp[M][(1<<N)-1]<<endl;
}

