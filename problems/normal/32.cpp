#include <iostream>
using namespace std;
int main()
{
  int N,Y;
  cin>>N>>Y;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=N-i;j++){
      int k=N-(i+j);
      if(i*1000+j*5000+k*10000==Y){
        cout<<k<<" "<<j<<" "<<i<<endl;
        cout<<(i+j*5+10*k)*1000<<endl;
        return 0;
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
}
