#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define g(i,t) get<i>(t)
#define fi first
#define se second

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;

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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,A,B;
  string S;
  cin >> N >> A >> B >> S;
  int Ac = 0;
  int Bc = 0;
  repa(x,S){
    if(x == 'c'){
      cout << "No" << endl;
    }else if(Ac + Bc == A + B){
      cout << "No" << endl;
    }else if(x == 'a'){
      Ac++;
      cout << "Yes" << endl;
    }else if(Bc < B){
      Bc++;
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}