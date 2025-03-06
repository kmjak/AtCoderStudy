#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
  int N;cin>>N;
  map<int,int> M;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    M[x%4]++;
  }
  int not4=M[1]+M[3]+(M[2]==0?0:1);
  cout<<(M[0]+1>=not4?"Yes":"No")<<endl;
}
