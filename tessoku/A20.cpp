#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string S,T;
int N,M;
vector<vector<int>> dp(2010,vector<int>(2010,0));

int main()
{
  cin>>S>>T;N=S.size();M=T.size();
  for(int i=1;i<=N;i++)for(int j=1;j<=M;j++){
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    if(S[i-1]==T[j-1]){
      dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
  }
  cout<<dp[N][M]<<endl;
  return 0;
}
