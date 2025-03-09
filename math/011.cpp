#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<long long> primes;
long long N;
void AllPrime(long long max_p)
{
  if(max_p>=2)primes.emplace_back(2);
  for(long long i=3;i<max_p+1;i+=2){
    cout<<i<<endl;
    bool flag=true;
    for(long long x:primes){
      if(i%x==0)flag=false;
    }
    if(flag)primes.emplace_back(i);
  }
}
bool isPrime()
{
  long long max_p=pow(N,0.5);
  //AllPrime(max_p);
  for(long long i=3;i<max_p+1;i+=2){
    if(N%i==0)return false;
  }
  return true;
}
int main()
{
  cin>>N;
  if(N%2==0){
    cout<<"No"<<endl;
    return 0;
  }
  bool res = isPrime();
  if(res)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
