#include <iostream>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
ll A;
ll B;
ll res=1;

ll solve()
{
  ll res=1;
  for(int i=0;i<30;i++){
    if((B/(1<<i))%2==1)res=(res*A)%MOD;
    A=(A*A)%MOD;
  }
  return res;
}

int main()
{
  cin>>A>>B;
  cout<<solve()<<endl;
}
