#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  vector<long long> A(3);
  for(int i=0;i<3;i++)cin>>A[i];
  sort(A.begin(),A.end());
  if(A[2]<0||A[0]>0){
    cout<<"No"<<endl;
    return 0;
  }
  // cout<<A[2]+A[0]<<endl;
  if(A[2]+A[0]==-A[1]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
