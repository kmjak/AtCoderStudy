#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<long long> A(1e5+10,0);
int main()
{
  cin>>N;
  for(int i=0;i<N;i++)cin>>A[i];
  long long a=A[0];
  for(long long i=1;i<N;i++){
    long long tmp=a;
    a=max(a,A[i]);
    long long b=min(tmp,A[i]);
    while(b){
      tmp=a;
      a=b;
      b=tmp%b;
    }
  }
  cout<<a<<endl;
}
