#include <iostream>
#include <map>
using namespace std;
int Q;
map<string,int> score;
int main()
{
  cin>>Q;
  while(Q--){
    int opt;cin>>opt;
    string s;
    cin>>s;
    if(opt==1){
      int x;
      cin>>x;
      score[s]=x;
    }else{
      cout<<score[s]<<endl;
    }
  }
}
