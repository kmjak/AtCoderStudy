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
  int N,Q;cin>>N>>Q;

  ll cur=0;
  vb F(N,false);
  while(Q--){
    int a;cin>>a;
    a--;
    F[a]=!F[a];

    if(a == 0){
      if(F[a] == true && F[a+1] == false){
        cur++;
      }else if(F[a] == false && F[a+1] == false){
        cur--;
      }
    }else if(a+1 == N){
      if(F[a] == true && F[a-1] == false){
        cur++;
      }else if(F[a] == false && F[a-1] == false){
        cur--;
      }
    }else{
      if(F[a] == true){
        if((F[a+1] || a+1 == N) == true && (F[a-1] || a == 0) == true){
          cur--;
        }else if((F[a+1] || a+1 == N) == false && (F[a-1] || a == 0) == false){
          cur++;
        }
      }else{
        if((F[a+1] || a+1 == N) == true && (F[a-1] || a == 0) == true){
          cur++;
        }else if((F[a+1] || a+1 == N) == false && (F[a-1] || a == 0) == false){
          cur--;
        }
      }
    }
    cout<<cur<<endl;

    // for(auto x: F){
    //   cout<<x << " ";
    // }
    // cout<<endl;
  }

  return 0;
}