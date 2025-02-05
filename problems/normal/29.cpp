#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S,T;
int main()
{
  cin>>S>>T;
  sort(S.begin(),S.end());
  sort(T.rbegin(),T.rend());
  if(S<T){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
