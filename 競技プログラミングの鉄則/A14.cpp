#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

ll N,K;

int main()
{
  cin>>N>>K;
  vector<ll> A(N),C(N),AB(N*N),CD(N*N);
  for(int i=0;i<N;i++)cin>>A[i];
  for(int i=0;i<N;i++){
    ll b;
    cin>>b;
    for(int j=0;j<N;j++)AB[N*i+j]=b+A[j];
  }
  for(int i=0;i<N;i++)cin>>C[i];
  for(int i=0;i<N;i++){
    ll d;
    cin>>d;
    for(int j=0;j<N;j++)CD[N*i+j]=d+C[j];
  }
  sort(AB.begin(),AB.end());
  sort(CD.begin(),CD.end());
  for(int i=0;i<N*N;i++){
    if(binary_search(CD.begin(),CD.end(),K-AB[i])){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
