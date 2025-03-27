#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
  int N,Q;
  cin>>N>>Q;
  vector<int> A(N);
  for(int i=0;i<N;i++)A[i]=i+1;
  int cnt=0;
  while(Q--){
    int opt;
    cin>>opt;
    if(opt==1){
      int x,y;
      cin>>x>>y;
      if(cnt%2==1)x=N+1-x;
      x--;
      A[x]=y;
    }else if(opt==2){
      cnt++;
    }else{
      int x;
      cin>>x;
      if(cnt%2==1)x=N+1-x;
      x--;
      cout<<A[x]<<endl;
    }
  }
}
