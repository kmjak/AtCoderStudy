#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,S;
vector<long long> A(65,0);
vector<bool> dp(1e4+10,false);
int main()
{
  cin>>N>>S;
  for(int i=0;i<N;i++)cin>>A[i];
  dp[0]=true;
  for(int i=0;i<N;i++){
    for(int j=S;j>=0;j--){
      if(dp[j]&&j+A[i]<=S)dp[j+A[i]]=true;
    }
  }
  // for(int i=0;i<S;i++)cout<<dp[i]<<" ";
  if(dp[S])cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
