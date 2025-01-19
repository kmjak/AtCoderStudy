#include <iostream>
#include <vector>
using namespace std;
using ll=long long;

ll N,K;
ll MAX=1e9;
vector<ll> vec(1e5+10);

bool solve(ll x)
{
  ll sum=0;
  for(int i=0;i<N;i++)sum+=x/vec[i];
  if(sum>=K)return 1;
  return 0;
}
int main()
{
  cin>>N>>K;
  for(int i=0;i<N;i++)cin>>vec[i];
  ll s=0,l=MAX;
  while(s<l){
    ll m=(s+l)/2;
    // cout<<m<<endl;
    if(solve(m))l=m;
    else s=m+1;
  }
  cout<<s<<endl;
}
