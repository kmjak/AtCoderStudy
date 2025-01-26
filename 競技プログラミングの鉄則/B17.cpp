#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> H(1e5+10,0),dp(1e5+10,0);
int N;
int main()
{
  cin>>N;
  for(int i=0;i<N;i++)cin>>H[i];
  dp[2]=abs(H[0]-H[1]);
  for(int i=3;i<N+2;i++){
    dp[i]=min(dp[i-1]+abs(H[i-2]-H[i-1]),dp[i-2]+abs(H[i-3]-H[i-1]));
  }
  // for(int i=1;i<=N;i++)cout<<dp[i]<<endl;
  int r=N;
  vector<int> res;
  while(true){
    res.emplace_back(r);
    if(r==1)break;
    if(dp[r]==dp[r-1]+abs(H[r-1]-H[r-2]))r--;
    else r-=2;
  }
  sort(res.begin(),res.end());
  cout<<res.size()<<endl;
  for(int x:res)cout<<x<<" ";
  cout<<endl;
}
