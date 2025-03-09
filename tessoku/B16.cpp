#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> H(1e5+10,0),dp(1e5+10,1e12+10);

int main()
{
  int N;
  cin>>N;
  for(int i=0;i<N;i++)cin>>H[i];
  dp[0]=0;
  for(int i=0;i<N-1;i++){
    dp[i+1]=min(dp[i+1],dp[i]+abs(H[i]-H[i+1]));
    if(i<N-1)dp[i+2]=min(dp[i+2],dp[i]+abs(H[i]-H[i+2]));
  }
  cout<<dp[N-1]<<endl;
}
