#include <iostream>
#include <algorithm>
using namespace std;
long long A,B;
int main()
{
  cin>>A>>B;
  long long res=1;
  long long i=2;
  while(i<max(A,B)/2+1){
    if(A%i==0&&B%i==0){
      res*=i;
      A/=i;B/=i;
      continue;
    }
    i++;
  }
  cout<<res<<endl;
}

