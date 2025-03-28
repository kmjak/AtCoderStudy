#include <iostream>
#include <map>
#include <set>
using namespace std;
int N;
map<long long,int> cnt;
set<int> appear;
int main()
{
  cin>>N;
  for(int i=0;i<N;i++){
    long long x;cin>>x;
    cnt[x]++;
    appear.insert(x);
  }
  long long res=0;
  for(auto x: appear){
    long long n=cnt[x];
    if(n==1||n==0)continue;
    res+=(n-1)*n/2;
  }
  cout<<res<<endl;
}
