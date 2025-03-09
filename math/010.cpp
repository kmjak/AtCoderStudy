#include <iostream>
using namespace std;
int N;
long long f(int idx)
{
  if(idx==1)return 1;
  return f(idx-1)*idx;
}
int main()
{
  cin>>N;
  cout<<f(N)<<endl;
}
