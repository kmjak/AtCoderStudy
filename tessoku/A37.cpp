#include <iostream>
using namespace std;

int main()
{
  long long N,M,B;
  cin>>N>>M>>B;
  long long res=N*M*B;
  for(int i=0;i<N;i++){
    long long x;
    cin>>x;
    res+=(M*x);
  }
  for(int i=0;i<M;i++){
    long long x;
    cin>>x;
    res+=(N*x);
  }
  cout<<res<<endl;
}
