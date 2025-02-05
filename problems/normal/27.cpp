#include <iostream>
#include <string>
using namespace std;
int N;
int res=0;
string S,T;
int main()
{
  cin>>N>>S>>T;
  int i=0;
  while(i<N){
    if(S.substr(i,N-i)==T.substr(0,N-i))break;
    i++;
  }
  cout<<N+i<<endl;
}
