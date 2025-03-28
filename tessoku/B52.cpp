#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
string S;
int N,X;
int main()
{
  cin>>N>>X>>S;
  X--;
  q.push(X);
  while(!q.empty()){
    int i=q.front();
    q.pop();
    S[i]='@';
    if(S[i+1]=='.')q.push(i+1);
    if(S[i-1]=='.')q.push(i-1);
  }
  cout<<S<<endl;
}
