#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int N,M;
  cin>>N>>M;
  vector<int> Player(N,M);
  for(int i=0;i<M;i++){
    int x;
    cin>>x;
    Player[x-1]--;
  }
  for(int i=0;i<N;i++)cout<<Player[i]<<endl;
}
