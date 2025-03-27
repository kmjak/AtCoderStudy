#include <string>
#include <iostream>
using namespace std;
int main()
{
  int N;
  char C;
  string S;
  cin>>N>>C>>S;
  int score=0;
  for(auto x:S)score+=(x=='B'?2:x=='R'?1:0);
  score%=3;
  if((score==2&&C=='B')||(score==1&&C=='R')||(score==0&&C=='W')){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
