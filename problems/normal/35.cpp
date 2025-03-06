#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
ll gcd(ll a, ll b)
{
  if(a>b){
    swap(a,b);
  }
  while(a){
    b=b%a;
    swap(a,b);
  }
  return b;
}
int main()
{
  ll A,B,C,D;
  cin>>A>>B>>C>>D;
  ll n=B-A;
  A--;
  ll gc=gcd(C,D);
  ll An=(A/C+A/D-A/(C*D/gc));
  ll Bn=(B/C+B/D-B/(C*D/gc));
  cout<<n-(Bn-An)+1<<endl;
}
