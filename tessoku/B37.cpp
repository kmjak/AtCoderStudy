#include <iostream>
using namespace std;
int f(int n)
{
  int sum=0;
  int x=10;
  while(n>=x){
    sum+=n%x;
    n/=x;
  }
  sum+=n;
  return sum;
}
int main()
{
  for(int i=0;i<=30;i++){
    cout<<i<<" "<<f(i)<<endl;
  }
}
