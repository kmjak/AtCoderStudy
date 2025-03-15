#include <iostream>
#include <map>
using namespace std;
int main()
{
  int N;
  cin>>N;
  // なぜかここはintだとWAになった。N<=2e5&&1<=Ai<=100だから絶対intで足りると思った
  map<long long ,long long> cnt;
  for(int i=0;i<N;i++){
    long long x;
    cin>>x;
    cnt[x]++;
  }
  long long res=0;
  for(int i=1;i<=100;i++){
    if(cnt[i]<3)continue;
    res+=(cnt[i])*(cnt[i]-1)*(cnt[i]-2)/6;
  }
  cout<<res<<endl;
}
