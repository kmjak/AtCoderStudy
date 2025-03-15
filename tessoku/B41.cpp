#include <iostream>
#include <vector>
using namespace std;

long long res=0;
bool isFinished=false;
int X,Y;
void dfs(int x, int y, vector<pair<int,int>> route)
{
  if(isFinished)return;
  if(x==X&&y==Y){
    cout<<route.size()<<endl;
    for(auto x: route){
      cout<<x.first<<" "<<x.second<<endl;
    }
    isFinished=true;
    return;
  }
  if(x+y<=X){
    route.emplace_back(x+y,y);
    dfs(x+y,y,route);
    route.pop_back();
  }
  if(x+y<=Y){
    route.emplace_back(x,x+y);
    dfs(x,x+y,route);
    route.pop_back();
  }
}
int main()
{
  cin>>X>>Y;
  dfs(1,1,vector<pair<int,int>>{});
}
