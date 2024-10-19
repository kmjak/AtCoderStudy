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
  int N,Q;
  cin >> N >> Q;
  pi current = {0,1};
  int score = 0;
  rep(i,0,Q){
    char c;
    int t;
    cin >> c >> t;
    t--;
    if(c == 'L'){
      int tmp1 = abs(current.first - t);
      int tmp2 =  N - abs(current.second - t);
      pi next1 = {t,current.second};
      pi next2 = {t,current.second};
      if(min(current.first,t) < current.second &&  max(current.first,t) > current.second){
        tmp1++;
      }else{
        tmp2++;
      }

    }
  }
  cout << score << endl;
  return 0;
}