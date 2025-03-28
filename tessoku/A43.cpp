#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int N,L;
  long long res=0;
  cin>>N>>L;
  for(int i=0;i<N;i++){
    long long m;char c;
    cin>>m>>c;
    if(c=='E')m=L-m;
    res=max(res,m);
  }
  cout<<res<<endl;
}
