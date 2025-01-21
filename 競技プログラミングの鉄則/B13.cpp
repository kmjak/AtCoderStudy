#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

ll N,K;
ll sum=0,res=0;
vector<ll> A(1e5+10),R(1e5+10,1);

int main()
{
  cin>>N>>K;
  for(ll i=0;i<N;i++){
    cin>>A[i];
    if(A[i]<=K)res++;
  }
  sum=A[0];
  for(ll i=0;i<N-1;i++){
    if(i!=0)R[i]=R[i-1];
    while(R[i]<N&&sum+A[R[i]]<=K){
      sum+=A[R[i]];
      R[i]++;
    }
    // cout<<sum<<endl;
    if(sum!=0)sum-=A[i];
    // cout<<R[i]<<endl;
  }
  for(int i=0;i<N-1;i++){
    res+=R[i]-i-1;
  }
  cout<<res<<endl;
}

