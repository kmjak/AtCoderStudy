#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int Q;
priority_queue<int,vector<int>,greater<int>> pq;
int main()
{
  cin>>Q;
  while(Q--){
    int opt;
    cin>>opt;
    if(opt==1){
      int x;
      cin>>x;
      pq.push(x);
    }else if(opt==2){
      cout<<pq.top()<<endl;
    }else{
      pq.pop();
    }
  }
}
