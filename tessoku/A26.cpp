#include <iostream>
#include <cmath>
using namespace std;

int Q;
bool isPrime(int m,int target)
{
  for(int i=3;i<=m;i++){
    if(target%i==0)return false;
  }
  return true;
}

int main()
{
  cin>>Q;
  while(Q--){
    int x;
    cin>>x;
    if(x%2==0){
      if(x==2)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
      continue;
    }
    int m=pow(x,0.5);
    if(isPrime(m,x)){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}
