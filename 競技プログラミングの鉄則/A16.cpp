#include <iostream>
#include <vector>
using namespace std;
int MAX=1e5;
int N;
vector<int> A(1e5+10),B(1e5+10);
vector<int> dp(1e5+10,0);
int main()
{
  cin>>N;
  N--;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=1;i<N;i++)cin>>B[i];
  for(int i=0;i<N+1;i++)dp[i+1]=A[0];
  for(int i=2;i<N+1;i++){
    if(dp[i-1]+A[i-1]>dp[i-2]+B[i-1]){
      dp[i]=dp[i-2]+B[i-1];
    }else{
      dp[i]=dp[i-1]+A[i-1];
    }
  }
  cout<<dp[N]<<endl;
}
