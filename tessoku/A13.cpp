#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll N,K,res=0;
int main()
{
  cin>>N>>K;
  vector<ll> A(N),R(N,0);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N-1;i++){
    if(i==0)R[i]=1;
    else R[i]=R[i-1];
    while(R[i]<N&&abs(A[i]-A[R[i]])<=K)R[i]++;
  }
  for(int i=0;i<N-1;i++)res+=R[i]-i-1;
  cout<<res<<endl;
}
