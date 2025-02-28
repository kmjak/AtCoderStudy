#include <vector>
#include <iostream>
using namespace std;
using vl=vector<long long>;
const long long MOD=1000000007;
int N;
long long f(int k,long long now, long long prev)
{
  long long next=(now+prev)%MOD;
  if(k==N)return next;
  return f(k+1,next,now);
}
int main()
{
  cin>>N;
  cout<<f(2,1,0)<<endl;
}
