#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct pnt{
  int idx;
  int score;
};

int N;
vector<pnt> A(2010);
vector<vector<int>> dp(2010,vector<int>(2010,0));
int main()
{
  cin>>N;
  for(int i=1;i<=N;i++)cin>>A[i].idx>>A[i].score;
  dp[1][N]=0;
  for(int i = N-2;i>=0;i--){
    for(int l=1;l<=N-i;l++){
      int r=l+i;
      int score1=0,score2=0;
      if(l<=A[l-1].idx&&A[l-1].idx<=r)score1=A[l-1].score;
      if(l<=A[r+1].idx&&A[r+1].idx<=r)score2=A[r+1].score;
      if(l==1)dp[l][r]=dp[l][r+1]+score2;
      else if(r==N) dp[l][r]=dp[l-1][r]+score1;
      else dp[l][r]=max(dp[l-1][r]+score1,dp[l][r+1]+score2);
    }
  }
  int res=0;
  for(int i=1;i<=N;i++)res=max(res,dp[i][i]);
  cout<<res<<endl;
}
