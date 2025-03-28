#include <stack>
#include <iostream>
#include <string>
using namespace std;
stack<int> st;
string S;
int N;
int main()
{
  cin>>S;
  N=S.size();
  for(int i=0;i<N;i++){
    if(S[i]=='(')st.push(i);
    else{
      int j=st.top();
      st.pop();
      cout<<j+1<<" "<<i+1<<endl;
    }
  }
}
