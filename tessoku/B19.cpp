#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long W;
long long MAX=1e6;
vector<long long> Cost(110,0),Val(110,0);
vector<vector<long long>> dp(110,vector<long long>(MAX+10,-1));
int main()
{
  cin>>N>>W;
  long long res=0;
  dp[0][0]=0;
  for(int i=1;i<=N;i++)cin>>Cost[i]>>Val[i];
  for(int i=1;i<=N;i++){
    // cout<<"--------------------"<<endl;
    // cout<<i<<endl;;
    for(int j=MAX+5;j>=0;j--){
      if(dp[i-1][j]!=-1){
        if(dp[i][j]==-1)dp[i][j]=dp[i-1][j];
        if(dp[i][j+Val[i]]==-1){
          dp[i][j+Val[i]]=dp[i][j]+Cost[i];
          // cout<<j+Val[i]<<" "<<dp[i][j+Val[i]]<<endl;
          continue;
        }
        dp[i][j+Val[i]]=min(dp[i][j+Val[i]],dp[i][j]+Cost[i]);
        // cout<<dp[i][j]+Cost[i]<<" "<<dp[i][j+Val[i]]<<endl;
      }
    }
  }
  for(int i=0;i<=MAX+5;i++){
    if(dp[N][i]<=W&&dp[N][i]!=-1)res=i;
  }
  cout<<res<<endl;
}
