#include<queue>
#include <iostream>
#include <string>
using namespace std;
queue<string> q;
int Q;
int main()
{
  cin>>Q;
  while(Q--){
    int opt;
    cin>>opt;
    if(opt==1){
      string s;
      cin>>s;
      q.push(s);
    }else if(opt==2){
      cout<<q.front()<<endl;
    }else{
      q.pop();
    }
  }
}
