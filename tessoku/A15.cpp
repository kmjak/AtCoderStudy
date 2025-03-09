#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll=long long;
vector<ll> A(1e5);
set<ll> S;
ll N;

int main()
{
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>A[i];
    S.insert(A[i]);
  }
  vector<ll> uniq;
  for(auto x:S)uniq.push_back(x);
  for(int i=0;i<N;i++){
    ll s=0,l=uniq.size();
    while(l-s>1){
      int m=(l+s)/2;
      if(A[i]<uniq[m])l=m;
      else s=m;
    }
    cout<<s+1<<" ";
  }
  cout<<endl;
}
