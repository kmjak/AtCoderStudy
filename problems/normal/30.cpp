#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N,M;
int main()
{
  cin>>N>>M;
  if(N-2>0&&M-2>0){
    cout<<(N-2)*(M-2)<<endl;
  }
  if(N==1&&M==1){
    cout<<1<<endl;
  }
  if((N==1||M==1)&&N!=M){
    cout<<N*M-2<<endl;
  }
  if(N==2||M==2){
    cout<<0<<endl;
  }
}
