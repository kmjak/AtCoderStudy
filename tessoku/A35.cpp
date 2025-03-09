#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> dp(2010,vector<int>(2010,0));
int main()
{
  int N;
  cin>>N;
  vector<int> A(N+1);
  for(int i=1;i<=N;i++)cin>>A[i];
  for(int i=1;i<=N;i++)dp[N][i]=A[i];
  for(int i=N-1;i>0;i--){
    for(int j=1;j<=i;j++){
      if(i%2==1)dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
      else dp[i][j]=min(dp[i+1][j],dp[i+1][j+1]);
    }
  }
  cout<<dp[1][1]<<endl;
  //for(int i=0;i<=N;i++){
  //  for(int j=0;j<=N;j++){
  //    cout<<dp[i][j]<<" ";
  //  }
  //  cout<<endl;
  //}
}
