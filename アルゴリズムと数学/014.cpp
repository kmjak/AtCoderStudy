#include <iostream>
#include <cmath>
using namespace std;
long long N;
int main()
{
  cin>>N;
  while(N%2==0&&N!=1){
    cout<<2<<" ";
    N/=2;
  }
  long long i=3;
  long long max_p=pow(N,0.5)+1;
  while(i<max_p&&N!=1){
    if(N%i==0){
      cout<<i<<" ";
      N/=i;
      continue;
    }
    i++;
  }
  if(N!=1){
    cout<<N<<" ";
  }
  cout<<endl;
}
