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
      long long r=-1;
      for(auto n:se){
        if(n>=x){
          r=n;
          break;
        }
      }
      cout<<r<<endl;
    }
  }
}
