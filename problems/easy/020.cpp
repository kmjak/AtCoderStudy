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

#define tos(n) to_string(n)
#define toi(s) stoi(s)

#define NO cout << "No" << endl;
#define YES cout << "Yes" << endl;

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

int MAX = 1000010;

int f(int& N)
{
  if(N%2==0){
    N = N / 2;
    return N;
  }else{
    N = N*3 + 1;
    return N;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int S;
  cin >> S;
  vector<bool> a(MAX,false);
  a[S] = true;

  rep(i,1,MAX) {
    int tmp = f(S);
    if(a[tmp]){
      cout << i+1 << '\n';
      return 0;
    }
    a[tmp] = true;
  }


  return 0;
}