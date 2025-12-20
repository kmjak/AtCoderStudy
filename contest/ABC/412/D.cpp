#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

using vvi=vector<vi>;
using vvll=vector<vll>;

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

struct pnt {
  ll x;
  ll y;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,M;
  cin>>N>>M;
  vvi G(N);
  for (int i=0; i<M; i++) {
    int a,b;
    cin>>a>>b;
    a--; b--;
    G[a].eb(b);
    G[b].eb(a);
  }

  int res=0;
  for(int i=0;i<N;i++){
    bool f=true;
    if(G[i].size()==2)continue;

    if(G[i].size()>2){
      for(int j=i+1;j<N;j++){
        if(G[j].size()>2){
          G[i].erase(remove(all(G[i]), j), G[i].end());
          G[j].erase(remove(all(G[j]), i), G[j].end());
          f=false;
          break;
        }
      }

      if(f){
        G[i].erase(remove(all(G[i]), (i+1)%N), G[i].end());
        G[(i+1)%N].erase(remove(all(G[(i+1)%N]), i), G[(i+1)%N].end());
      }
    }else{
      for(int j=i+1;j<N;j++){
        if(G[j].size()<2){
          G[i].eb(j);
          G[j].eb(i);
          f=false;
          break;
        }
      }
      if(f){
        G[i].eb((i+1)%N);
        G[(i+1)%N].eb(i);
      }
    }

    if(f==false){
      res++;
      i--;
    }
  }

    for(int i=N-1;i>=0;i--){
    bool f=true;
    if(G[i].size()==2)continue;
    if(G[i].size()>2){
      for(int j=i-1;j>=0;j--){
        if(G[j].size()>2){
          G[i].erase(remove(all(G[i]), j), G[i].end());
          G[j].erase(remove(all(G[j]), i), G[j].end());
          f=false;
          break;
        }
      }
    }else{
      for(int j=i-1;j>=0;j--){
        if(G[j].size()<2){
          G[i].eb(j);
          G[j].eb(i);
          f=false;
          break;
        }
      }
    }

    if(f==false){
      res++;
      i--;
    }
  }
  cout<<res<<endl;
  return 0;
}