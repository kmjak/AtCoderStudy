#include <iostream>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
int N,R;

ll Power(ll a,ll b)
{
  ll res=1;
  for(int i=0;i<30;i++){
    if((b/(1<<i))%2==1)res=(res*a)%MOD;
    a=(a*a)%MOD;
  }
  return res;
}
int main()
{
  cin>>N>>R;
  ll A=1,B=1;
  for(int i=2;i<=N;i++)A=(A*i)%MOD;
  for(int i=2;i<=R;i++)B=(B*i)%MOD;
  for(int i=2;i<=N-R;i++)B=(B*i)%MOD;
  cout<<(A*Power(B,MOD-2))%MOD<<endl;
}
