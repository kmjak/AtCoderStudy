#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int,int>> Player(310);
int N,K;
int main()
{
  cin>>N>>K;
  for(int i=0;i<N;i++)cin>>Player[i].first>>Player[i].second;
  int res=0;
  for(int i=0;i<=100;i++){
    for(int j=0;j<=100;j++){
      int sum=0;
      for(int k=0;k<N;k++){
        auto [a,b]=Player[k];
        if(i<=a&&a<=i+K&&j<=b&&b<=j+K)sum++;
      }
      res=max(res,sum);
    }
  }
  cout<<res<<endl;
}
