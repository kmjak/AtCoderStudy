#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,K;
vector<int> sum(2*1e5+10,0);
double res=0;
int main()
{
  cin>>N>>K;
  int MAX=0;
  for(int i=1;i<=N;i++){
    int p;cin>>p;
    sum[i]=sum[i-1]+p;
  }

  for(int i=K;i<=N;i++){
    MAX=max(MAX,sum[i]-sum[i-K]);
  }
  res=MAX+K;
  res/=2;
  cout<<fixed<<setprecision(15)<<res<<endl;
}
