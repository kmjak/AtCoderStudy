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
  map<int, set<int>> X, Y;
  int H,W,N;
  cin>>H>>W>>N;
  for(int i=0;i<N;i++){
    int x,y;
    cin>>x>>y;
    X[x].insert(y);
    Y[y].insert(x);
  }

  int Q;cin>>Q;
  while(Q--){
    int opt;
    int res=0;
    cin>>opt;
    if(opt==1){
      int x;cin>>x;
      auto it = X.find(x);
      if(it != X.end()){
        for(int y : it->second){
          res++;
          Y[y].erase(x);
          if(Y[y].empty()) Y.erase(y);
          // cout << "--------" << x << " " << y << endl;
        }
        X.erase(x);
      }
    }else{
      int y;cin>>y;
      auto it = Y.find(y);
      if(it != Y.end()){
        for(int x : it->second){
          res++;
          X[x].erase(y);
          if(X[x].empty()) X.erase(x);
          // cout << "--------" << x << " " << y << endl;
        }
        Y.erase(y);
      }
    }
    cout<<res<<endl;
  }

  return 0;
}
