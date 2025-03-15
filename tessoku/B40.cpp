#include <iostream>
#include <map>
using namespace std;
int main()
{
  int N;
  cin>>N;
  map<int, int> cnt;
  for(int i=0;i<N;i++){
    long long x;
    cin>>x;
    x%=100;
    cnt[x]++;
  }
  long long res=0;
  if(cnt[0]>1){
    res+=(cnt[0]-1)*(cnt[0])/2;
  }
  if(cnt[50]>1){
    res+=(cnt[50]-1)*(cnt[50])/2;
  }
  for(int i=1;i<50;i++){
    res+=cnt[i]*cnt[100-i];
  }
  cout<<res<<endl;
}
