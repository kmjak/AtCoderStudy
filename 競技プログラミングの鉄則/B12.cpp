#include <iostream>
using namespace std;
using ll=long long;

int main()
{
  double N;
  cin>>N;
  double s=0,l=1e6;
  double prev=-1;
  while(s<l){
    double m=(s+l)/2.0;
    // cout<<m<<endl;
    double c=m*m*m+m;
    if(c>=N)l=m;
    else s=m;
    if(m==prev)break;
    prev=m;
  }
  cout<<l<<endl;
}
