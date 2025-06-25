#include <string>
#include <iostream>
using namespace std;
int N,Q;
string S;
int main()
{
  cin>>N>>Q>>S;
  while(Q--){
    int fl,fr,sl,sr;
    cin>>fl>>fr>>sl>>sr;
    fl--;sl--;
    fr-=fl;
    sr-=sl;
    cout<<(S.substr(fl,fr)==S.substr(sl,sr)?"Yes":"No")<<endl;
  }
}
