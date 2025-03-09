#include <iostream>
#include <vector>
using namespace std;
int N;
long long K;
vector<long long> A(1e5+10,0),sum(1e5+10,0);
int main()
{
  cin>>N>>K;
  for(int i=0;i<N;i++)cin>>A[i];
  long long res=0;
  for(int i=0;i<N;i++){
    sum[i+1]=sum[i]+A[i];
  }
  int j=1;
  for(int i=0;i<N;i++){
    while(j<N+1&&sum[j]-sum[i]<=K)j++;
    j=max(i+1,j);
    res+=j-i-1;
    //cout<<j<<endl;
  }
  cout<<res<<endl;
}
