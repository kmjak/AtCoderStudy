#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin>>N;
  vector<vector<int>> grid(N,vector<int>(N));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>grid[i][j];
    }
  }
  vector<int> line(N);
  for(int i=0;i<N;i++)line[i]=i;
  int Q;
  cin>>Q;
  while(Q--){
    int opt,x,y;
    cin>>opt>>x>>y;
    x--;y--;
    if(opt==1){
      swap(line[x],line[y]);
    }else{
      cout<<grid[line[x]][y]<<endl;
    }
  }
}
