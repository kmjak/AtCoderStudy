#include <stack>
#include <iostream>
#include <string>
using namespace std;

stack<string> st;
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
      st.push(s);
    }else if(opt==2){
      cout<<st.top()<<endl;
    }else{
      st.pop();
    }
  }
}
