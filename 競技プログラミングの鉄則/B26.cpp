#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> primes;
int main()
{
  int N;
  cin>>N;
  bool isPrime;
  primes.emplace_back(2);
  if(N>2){
    primes.emplace_back(3);
  }
  for(int i=6;i<=N;i+=6){
    for(int j=-1;j<2;j+=2){
      isPrime=true;
      for(auto prime:primes){
        if(prime>pow(i+j,0.5))break;
        if((i+j)%prime==0){
          isPrime=false;
        }
      }
      if(isPrime)primes.emplace_back(i+j);
    }
  }
  for(auto prime: primes)cout<<prime<<endl;
}

