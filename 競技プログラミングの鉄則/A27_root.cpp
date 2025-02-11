#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long A,B;
vector<long long> Avec;
int main()
{
  cin>>A>>B;
  long long res=1;
  long long N=pow(A,0.5),M=pow(B,0.5);
  for(long long i=1;i<=N;i++){
    if(A%i==0){
      Avec.emplace_back(A/i);
      Avec.emplace_back(i);
    }
  }
  sort(Avec.begin(),Avec.end());
  for(long long i=1;i<=M;i++){
    if(B%i==0){
      if(binary_search(Avec.begin(),Avec.end(),B/i)){
        res=max(res,B/i);
        continue;
      }
      if(binary_search(Avec.begin(),Avec.end(),i)){
        res=max(res,i);
      }
    }
  }
  cout<<res<<endl;
}
