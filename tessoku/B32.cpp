#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int N,K;
  cin>>N>>K;
  vector<int> A(K);
  for(int i=0;i<K;i++)cin>>A[i];
  vector<bool> dp(N+1,false);
  for(int i=0;i<=N;i++){
    for(int j=0;j<K;j++){
      if(i>=A[j]&&dp[i-A[j]]==false)dp[i]=true;
    }
  }
  cout<<(dp[N]?"First":"Second")<<endl;
}
