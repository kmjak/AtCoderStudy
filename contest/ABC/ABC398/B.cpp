#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

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

int randInt(int l, int r) {
  return l + rand() % (r - l + 1);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> V(7);
  for(int i=0; i<7; ++i) cin >> V[i];
  for(int i=0;i<7-4;i++){
    for(int j=i+1;j<7-3;j++){
      for(int k=j+1;k<7-2;k++){
        for(int l=k+1;l<7-1;l++){
          for(int m=l+1;m<7;m++){
            map<int,int> M;
            M[V[i]]++;
            M[V[j]]++;
            M[V[k]]++;
            M[V[l]]++;
            M[V[m]]++;
            bool isFullHouse2 = false;
            bool isFullHouse3 = false;
            for(auto x:M){
              if(x.second == 2) isFullHouse2 = true;
              if(x.second == 3) isFullHouse3 = true;
            }
            if(isFullHouse2 && isFullHouse3){
              cout << "Yes" << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}