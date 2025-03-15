#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
  int N,D;
  cin>>N>>D;
  vector<vector<int>> M(D);
  for(int i=0;i<N;i++){
    int x,y;
    cin>>x>>y;
    x--;
    M[x].emplace_back(y);
  }
  long long res=0;
  priority_queue<int> q;
  for(int i=0;i<D;i++){
    for(auto x: M[i])q.push(x);
    if(q.empty())continue;
    res+=q.top();
    q.pop();
  }
  cout<<res<<endl;
}
