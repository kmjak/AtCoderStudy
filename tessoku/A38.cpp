#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int D,N;
  cin>>D>>N;
  vector<int> work(D,24);
  for(int i=0;i<N;i++){
    int l,r,h;
    cin>>l>>r>>h;
    l--;
    for(int j=l;j<r;j++){
      work[j]=min(work[j],h);
    }
  }
  long long res=0;
  for(int i=0;i<D;i++)res+=work[i];
  cout<<res<<endl;
}
