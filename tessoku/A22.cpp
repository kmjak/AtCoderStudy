#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> dp(1e5+10,-1),A(1e5+10),B(1e5+10);
int main()
{
  cin>>N;
  dp[1]=0;
  for(int i=1;i<N;i++)cin>>A[i];
  for(int i=1;i<N;i++)cin>>B[i];
  for(int i=1;i<=N;i++){
    if(dp[i]!=-1){
      dp[A[i]]=max(dp[A[i]],dp[i]+100);
      dp[B[i]]=max(dp[B[i]],dp[i]+150);
    }
  }
 // for(int i=0;i<=N;i++)cout<<dp[i]<<endl;
  cout<<dp[N]<<endl;
}
