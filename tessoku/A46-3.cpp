#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

int N;
vector<int> X(160), Y(160), O(160);

int randInt(int a, int b) {
  return a + rand() % (b - a + 1);
}

double randDouble() {
  return 1.0*rand() / RAND_MAX;
}

double getDist(int i, int j) {
  return sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]));
}

double calcScore(){
  double sum=0;
  for(int i=1;i<=N;i++)sum+=getDist(O[i],O[i+1]);
  return sum;
}

int main()
{
  cin>>N;
  for(int i=0;i<N;i++) cin>>X[i]>>Y[i];
  O[1]=1;
  O[N+1]=1;
  for(int i=2;i<=N;i++)O[i]=i;

  double currentScore=calcScore();
  for(int t=1;t<=2e5;t++){
    int L=randInt(2,N);
    int R=randInt(2,N);
    if(L>R)swap(L,R);
    reverse(O.begin()+L,O.begin()+R+1);
    double newScore=calcScore();
    double T=30.00-28.00*t/2e5;
    double Probability=exp(min(0.0,(currentScore-newScore)/T));
    if(randDouble()<Probability){
      currentScore=newScore;
    }else{
      reverse(O.begin()+L,O.begin()+R+1);
    }
  }
  for(int i=1;i<=N+1;i++)cout<<O[i]<<endl;
}