#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin>>N;
  vector<pair<int,int>> movie(N);
  for(int i=0;i<N;i++)cin>>movie[i].second>>movie[i].first;
  sort(movie.begin(),movie.end(), [] (auto a, auto b){
      if(a.first==b.first)return a.second<b.second;
      return a.first<b.first;
    });
  int now=-1;
  int res=0;
  for(auto x:movie){
    if(now<=x.second){
      now=x.first;
      res++;
    }
  }
  cout<<res<<endl;
}
