#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,S;
vector<int> A(70);
vector<vector<bool>> dp(70,vector<bool>(1e7+10,false));

int main()
{
  dp[0][0]=true;
  cin>>N>>S;
  for(int i=0;i<N;i++){
    cin>>A[i];
    for(int j=0;j<S+1;j++){
      if(dp[i][j]){
        dp[i+1][j]=true;
        dp[i+1][j+A[i]]=true;
      }
    }
  }
  if(dp[N][S]==false){
    cout<<-1<<endl;
    return 0;
  }
  vector<int> res;
  int idx=N+1;
  int score=S;
  while(idx--&&score!=0){
    if(score-A[idx-1]<0)continue;
    if(dp[idx-1][score-A[idx-1]]){
      res.emplace_back(idx);
      score-=A[idx-1];
    }
  }
  cout<<res.size()<<endl;
  sort(res.begin(),res.end());
  for(int x:res)cout<<x<<" ";
  cout<<endl;
}
