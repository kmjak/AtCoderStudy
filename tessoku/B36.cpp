#include <iostream>
#include <string>
using namespace std;
int main()
{
  int N,K;
  string S;
  cin>>N>>K>>S;
  int ON=0;
  for(int i=0;i<N;i++)if(S[i]=='1')ON++;
  cout<<(ON%2==K%2?"Yes":"No")<<endl;
}
