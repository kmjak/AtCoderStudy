#include <iostream>
#include <algorithm>
using namespace std;
long long A,B;
int main()
{
  cin>>A>>B;
  long long MAX=max(A,B);
  long long MIN=min(A,B);
  while(MIN){
    MAX%=MIN;
    swap(MAX,MIN);
  }
  cout<<A*B/MAX<<endl;
}
