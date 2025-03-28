#include <set>
#include <iostream>
using namespace std;
set<long long> se;
int Q;
int main()
{
  cin>>Q;
  while(Q--){
    int opt;cin>>opt;
    long long x;
    cin>>x;
    if(opt==1){
      se.insert(x);
    }else if(opt==2){
      se.erase(x);
    }else{
      auto it=se.lower_bound(x);
      if(it==se.end())cout<<-1<<endl;
      else cout<<*it<<endl;
    }
  }
}
