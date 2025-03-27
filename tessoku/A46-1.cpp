#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N;
vector<int> X(160),Y(160);
vector<int> O(160);
vector<bool> visited(160,false);

double getDistance(int p,int q)
{
  return sqrt((X[p]-X[q])*(X[p]-X[q])+(Y[p]-Y[q])*(Y[p]-Y[q]));
}

void playGreedy()
{
  int currentOlace=1;
  for(int i=1;i<=N;i++)visited[i]=false;
  O[1]=1;
  visited[1]=true;
  for(int i=2;i<=N;i++){
    double minDist=10000.0;
    int minIdx=-1;
    for(int j=2;j<=N;j++){
      if(visited[j])continue;
      double dist=getDistance(currentOlace,j);
      if(minDist>dist){
        minDist=dist;
        minIdx=j;
      }
    }
    visited[minIdx]=true;
    O[i]=minIdx;
    currentOlace=minIdx;
  }
  O[N+1]=1;
}

int main()
{
  cin>>N;
  for(int i=1;i<=N;i++)cin>>X[i]>>Y[i];
  playGreedy();
  for(int i=1;i<=N+1;i++)cout<<O[i]<<endl;
}
