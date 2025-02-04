#include <iostream>
using namespace std;
long long N,MIN,MAX;
int main()
{
  cin>>N>>MIN>>MAX;
  if(MIN>MAX||(N==1&&MIN!=MAX)){
    cout<<0<<endl;
    return 0;
  }
  if(N==1&&MIN==MAX){
    cout<<1<<endl;
    return 0;
  }
  long long mi=MIN*(N-1)+MAX;
  long long ma=MAX*(N-1)+MIN;
  cout<<ma-mi+1<<endl;
}
