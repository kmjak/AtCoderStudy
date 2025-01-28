#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int INF=1e5+10;
vector<int> A(INF),B(INF),dp(INF);
vector<int> res;
int main()
{
  cin>>N;
  for(int i=2;i<=N;i++)cin>>A[i];
  for(int i=3;i<=N;i++)cin>>B[i];
  dp[1]=0;dp[2]=A[2];
  for(int i=3;i<=N+1;i++)dp[i]=min(dp[i-1]+A[i],dp[i-2]+B[i]);

  int r=N;
  while(true){
    res.emplace_back(r);
    if(r==1)break;
    if(dp[r-1]+A[r]==dp[r])r--;
    else r-=2;
  }
  sort(res.begin(),res.end());
  cout<<res.size()<<endl;
  for(int x:res)cout<<x<<" ";
  cout<<endl;
}
