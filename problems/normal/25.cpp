#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int N,K;
map<int,int> m;
vector<int> cnt;
long long res=0;
int main()
{
  cin>>N>>K;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    m[a]++;
  }
  int c=m.size();
  int border=c-K;
  if(border<=0){
    cout<<0<<endl;
    return 0;
  }
  for(const auto& [key,val]:m){
    cnt.emplace_back(val);
  }
  sort(cnt.begin(),cnt.end());
  for(int i=0;i<border;i++)res+=cnt[i];
  cout<<res<<endl;
}
