#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isFinished=false;
int X,Y;
void bfs()
{
  queue<pair<pair<int,int>,vector<pair<int,int>>>> q;
  q.emplace(make_pair(1,1),vector<pair<int,int>>{});
  while(!q.empty()){
    auto [now,route]=q.front();
    q.pop();
    if(now.first==X&&now.second==Y){
      cout<<route.size()<<endl;
      for(auto [x,y]:route){
        cout<<x<<" "<<y<<endl;
      }
      return;
    }
    int nx=now.first+now.second;
    if(nx<=X){
      route.emplace_back(make_pair(nx,now.second));
      q.emplace(make_pair(nx,now.second),route);
      route.pop_back();
    }
    if(nx<=Y){
      route.emplace_back(make_pair(now.first,nx));
      q.emplace(make_pair(now.first,nx),route);
      route.pop_back();
    }
  }
}
int main()
{
  cin>>X>>Y;
  bfs();
}
