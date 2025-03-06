#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  string S;
  string res="";
  cin>>S;
  int N=S.size();
  int len=0;
  for(int i=0;i<N;i++){
    if(S[i]=='B'){
      len=max(len-1,0);
      res=res.substr(0,len);
    }
    else{
      len++;
      res+=S[i];
    }
  }
  cout<<res<<endl;
}
