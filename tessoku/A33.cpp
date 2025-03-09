#include <iostream>
using namespace std;
int main()
{
  int N;
  cin>>N;
  long long res=0;
  for(int i=0;i<N;i++){
    long long x;
    cin>>x;
    res^=x;
  }
  cout<<(res!=0?"First":"Second")<<endl;
}
