#include <iostream>
using namespace std;
int N;
long long res=0;
int main()
{
  cin>>N;
  while(N--){
    char c;
    int n;
    cin>>c>>n;
    if(c=='+')res+=n;
    else if(c=='-')res-=n;
    else res*=n;
    if(res<0)res+=10000;
    res%=10000;
    cout<<res<<endl;
  }
}
