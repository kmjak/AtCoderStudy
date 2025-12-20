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

using namespace std;

using ll=long long int;
using pi=pair<int,int>;

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
  string S,T;
  cin >> S >> T;
  vc tmp;
  repa(x,S){
    if(x == tolower(T[0]) || x == tolower(T[1]) || x == tolower(T[2])) tmp.pb(toupper(x));
  }
  int C = tmp.size();
  int prev = 0;
  if(T.back() == 'X') T = T.substr(0,2);
  int T_size = T.size();
  int i = 0;
  int j = 0;
  while(i != C){
    if(tmp[i] == T[j]){
      j++;
    }
    i++;
  }
  if(j == T_size) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}