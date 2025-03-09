#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<bool> dp(1e5+10);
int main()
{
  int N,A,B;
  cin>>N>>A>>B;
  for(int i=0;i<=N;i++){
    if(i>=A&&dp[i-A]==false)dp[i]=true;
    else if(i>=B&&dp[i-B]==false)dp[i]=true;
    else dp[i]=false;
  }
  cout<<(dp[N]?"First":"Second")<<endl;
}
