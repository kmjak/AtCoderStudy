#include <queue>
#include <iostream>
using namespace std;
priority_queue<int> pq;
int Q;
const int MAX=1e6;
int main()
{
  cin>>Q;
  while(Q--){
    int opt;cin>>opt;
    if(opt==1){
      int x;cin>>x;
      pq.push(MAX-x);
    }else if(opt==2){
      cout<<MAX-pq.top()<<endl;
    }else{
      pq.pop();
    }
  }
}
