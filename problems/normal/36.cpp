#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  long long N,X;
  cin>>N>>X;
  vector<long long> A(N);
  for(int i=0;i<N;i++)cin>>A[i];
  sort(A.begin(),A.end());
  long long res=A[0]-X+A[N-1];
  cout<<res<<endl;
}
