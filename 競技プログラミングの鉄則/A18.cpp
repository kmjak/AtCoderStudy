#include <iostream>
#include <vector>
using namespace std;
int N,S;
vector<int> A(1e4+10,0);
vector<vector<bool>> dp(70,vector<bool>(1e7+10,false));
int main()
{
  cin>>N>>S;
  dp[0][0]=true;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++){
    for(int j=0;j<S+1;j++){
      if(dp[i][j]){
        dp[i+1][j]=true;
        // if(j+A[i]>=N)continue;
        dp[i+1][j+A[i]]=true;
      }
    }
  }
  // for(int i=0;i<S;i++)cout<<dp[N][i]<<" ";

  if(dp[N][S]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;
}
