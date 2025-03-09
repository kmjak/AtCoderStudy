#include <iostream>
#include <cmath>
using namespace std;
long long N;
int main()
{
  cin>>N;
  if(N==1){
    cout<<1<<endl;
    return 0;
  }
  cout<<1<<endl;
  cout<<N<<endl;
  for(int i=2;i<pow(N,0.5);i++){
    if(N%i==0){
      cout<<i<<endl;
      cout<<N/i<<endl;
    }
  }
  return 0;
}
