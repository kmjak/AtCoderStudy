#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll=long long;

ll N,K;
ll calc(int k)
{
  if(k==1) return 2;
  return 2*calc(k-1);
}

int MAX=calc(16);
vector<ll> P(MAX+20,0),A(30,0);

int main()
{
  cin>>N>>K;
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<1<<15;i++){
    ll sum=0;
    for(int j=0;j<15;j++){
      if(1&(i>>j))sum+=A[j];
    }
    P[i]=sum;
    if(sum==K){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  sort(P.begin(),P.end());
  for(int i=0;i<1<<15;i++){
    ll sum=0;
    for(int j=0;j<15;j++){
      if(1&(i>>j))sum+=A[15+j];
    }
    if(binary_search(P.begin(),P.end(),K-sum)){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
