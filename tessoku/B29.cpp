#include <iostream>
#include <cmath>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
ll A;
ll B;
ll res=1;

int maxLen()
{
  ll MAXB=1e18;
  int n=log2(MAXB)+1;
  return n;

}

ll solve()
{
  ll res=1;
  int MAX=maxLen();
  for(int i=0;i<MAX;i++){
    if((B>>i)%2==1)res=(res*A)%MOD;
    A=(A*A)%MOD;
  }
  return res;
}

int main()
{
  cin>>A>>B;
  cout<<solve()<<endl;
}
