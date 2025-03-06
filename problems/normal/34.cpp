#include <iostream>
#include <vector>
using namespace std;
int N,K;
int solve(int k, int n)
{
  if(n+K>=N)return k+1;
  return solve(k+1,n+K-1);
}
int main()
{
  cin>>N>>K;
  vector<int> A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  cout<<solve(0,0)<<endl;
}
