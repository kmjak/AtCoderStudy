#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct contents {
  long long minute;
  queue<int> q;
};

long long INF=1e5+10;
vector<int> A(INF+10),B(INF+10);
vector<contents> dp(INF+10, contents {100000100, {}});
int N;

int main()
{
  cin>>N;
  N--;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N-1;i++)cin>>B[i];

  dp[0].minute=0;
  dp[0].q.push(1);
  for(int i=0;i<N;i++){
    if(dp[i+1].minute>=dp[i].minute+A[i]){
      dp[i+1]=dp[i];
      dp[i+1].minute+=A[i];
      dp[i+1].q.push(i+2);
    }
    if(i<N-1&&dp[i+2].minute>=dp[i].minute+B[i]){
      dp[i+2]=dp[i];
      dp[i+2].minute+=B[i];
      dp[i+2].q.push(i+3);
    }
  }
  cout<<dp[N].q.size()<<endl;
  while(!dp[N].q.empty()){
    int n=dp[N].q.front();
    dp[N].q.pop();
    cout<<n<<" ";
  }
  cout<<endl;
}
