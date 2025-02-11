#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,LEN;
vector<int> A(1e5+10),dp(1e5+10,0),L(1e5+10,0);

int main()
{
  cin>>N;
  for(int i=1;i<=N;i++)cin>>A[i];
  for(int i=1;i<=N;i++){
    int p=lower_bound(L.begin()+1,L.begin()+LEN+1,A[i])-L.begin();
    dp[i]=p;
    L[dp[i]]=A[i];
    if(dp[i]>LEN)LEN++;
  }
  cout<<LEN<<endl;
}
