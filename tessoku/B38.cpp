#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  string S;
  cin>>N>>S;
  vector<int> sum(N,1);
  for(int i=0;i<N-1;i++){
    if(S[i]=='A')sum[i+1]=sum[i]+1;
    else{
      sum[i+1]=1;
      if(sum[i]==1){
        int j=i;
        while(sum[j]==sum[j+1]){
          sum[j]++;
          j--;
        }
      }
    }
  }
  long long res=0;
  for(int i=0;i<N;i++)res+=sum[i];
  cout<<res<<endl;
}
