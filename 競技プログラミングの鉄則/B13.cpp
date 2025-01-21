#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll N,K;
ll res=0;
int main()
{
  cin>>N>>K;
  vector<ll> A(N),idx(N,1),sum(N+1,0);
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]<=K)res++;
    sum[i+1]+=sum[i]+A[i];
  }
  for(int i=0;i<N-1;i++){
    if(i!=0)idx[i]=idx[i-1];
    while(idx[i]<N&&sum[idx[i]+1]-sum[i]<=K)idx[i]++;
    // cout<<idx[i]<<endl;
  }
  for(int i=0;i<N-1;i++)res+=idx[i]-i-1;
  cout<<res<<endl;
}
