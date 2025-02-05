#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> res(3,-1);
int main()
{
  cin>>N>>M;
  for(int i=0;i<M;i++){
    int idx,val;
    cin>>idx>>val;
    idx--;
    if(res[idx]==val||res[idx]==-1){
      res[idx]=val;
    }else{
      cout<<-1<<endl;
      return 0;
    }
  }
  if(N==1&&(res[0]==-1||res[0]==0)){
    cout<<0<<endl;
  }else if(res[0]==0){
    cout<<-1<<endl;
  }else{
    if(res[0]==-1){
      res[0]=1;
    }
    for(int i=0;i<N;i++){
      if(res[i]==-1)res[i]=0;
      cout<<res[i];
    }
    cout<<endl;
  }
}
