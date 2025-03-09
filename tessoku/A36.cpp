#include <iostream>
using namespace std;
int main()
{
  long long N,K;
  cin>>N>>K;
  cout<<(K%2==0&&2*N-2<=K?"Yes":"No")<<endl;
}
