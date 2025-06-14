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
  ll N,Q;
  cin>>N>>Q;

  vll A(N,0);
  vll res(Q);
  for(ll i=0;i<Q;i++){
    ll x;
    cin>>x;
    if(x==0){
      ll minIndex = -1;
      ll minValue = LLONG_MAX;
      for(ll j=0;j<N;j++){
        // cout << A[i] << " " << minValue << endl;;

        if(A[j]<minValue){
          minValue = A[j];
          minIndex = j;
        }
      }
      A[minIndex]++;
      res[i] = minIndex + 1;
    }else{
      A[x-1]++;
      res[i] = x;
    }
  }
  for(auto r: res){
    cout << r <<endl;
  }
  return 0;
}