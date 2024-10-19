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
      if(min(current.first,t) < current.second &&  max(current.first,t) > current.second){
        score += N - abs(current.first - t);
        current.first = t;
      }else{
        score += abs(current.first - t);
        current.first = t;
      }
    }else{
      if(min(current.second,t) < current.first &&  max(current.second,t) > current.first){
        score += N - abs(current.second - t);
        current.second = t;
      }else{
        score += abs(current.second - t);
        current.second = t;
      }
    }
  }
  cout << score << endl;
  return 0;
}