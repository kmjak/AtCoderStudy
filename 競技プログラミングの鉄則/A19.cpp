#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N,W;
vector<long long> C(110,0),V(110,0);
vector<vector<long long>> dp(110,vector<long long> (1e5+10,0));

int  main()
{
  cin>>N>>W;
  for(long long i=0;i<N;i++)cin>>C[i]>>V[i];
  for(long long i=1;i<=N;i++){
    for(long long j=1;j<=W;j++){
      dp[i][j]=dp[i-1][j];
      if(j>=C[i-1]){
        if(dp[i][j]<dp[i-1][j-C[i-1]]+V[i-1])dp[i][j]=dp[i-1][j-C[i-1]]+V[i-1];
      }
    }
  }
  // for(long long i=0;i<N+1;i++){
    // for(long long j=0;j<=W;j++)cout<<dp[i][j]<<" ";
    // cout<<endl;
  // }
  cout<<dp[N][W]<<endl;
}

