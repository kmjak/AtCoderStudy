#include <iostream>
#include <vector>
using namespace std;
int N;
int res=0;
vector<long long> A;
int main()
{
  cin>>N;
  for(int i=1;i<=N;i++){
    long long a;
    cin>>a;
    if(i==1){
      A.emplace_back(a);
      continue;
    }
    if(A.back()==a)continue;
    A.emplace_back(a);
  }
  int cnt=A.size();
  if(N<2||cnt==1){
    cout<<1<<endl;
    return 0;
  }
  int v=0;
  int i=0;
  while(i<cnt){
    if(i+1==cnt){
      res++;
      break;
    }
    if(A[i]<A[i+1])v=1;
    else v=0;
    while(i+1<cnt&&((v==0&&A[i]>A[i+1])||(v==1&&A[i]<A[i+1])))i++;
    res++;i++;
  }
  cout<<res<<endl;
}
