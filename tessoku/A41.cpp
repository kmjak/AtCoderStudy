#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  string S;
  cin>>N>>S;
  bool isTrue=false;
  for(int i=0;i<N-2;i++){
    if(S[i]==S[i+1]&&S[i]==S[i+2])isTrue=true;
  }
  cout<<(isTrue?"Yes":"No")<<endl;
}
