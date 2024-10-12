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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // string S;
  // cin >> S;

  // map<char, vi> p;

  // rep(i, 0, S.size()) {
  //   p[S[i]].pb(i);
  // }

  // int res = 0;
  // for (const auto &e : p) {
  //   rep(i,0,e.second.size()-1){
  //     rep(j,i+1,e.second.size()){
  //       res += e.second[j] - e.second[i] - 1;
  //     }
  //   }
  // }
  // cout << res << endl;

  // return 0;
  
  string S;
  cin >> S;

  vector<vector<int>> p(26, vector<int>());
  for(int i=0; i<S.size(); ++i){
    p[S[i]-'A'].push_back(i);
  }

  ll res = 0;
  for(int c=0; c<26; ++c){
    int m = p[c].size();
    if(m < 2) continue;

    ll sum_b_pb = 0;
    for(int b=1; b<m; ++b){
      sum_b_pb += (ll)b * p[c][b];
    }

    ll sum_a_pa = 0;
    for(int a=0; a<m-1; ++a){
      sum_a_pa += (ll)(m-1 - a) * p[c][a];
    }

    res += sum_b_pb - sum_a_pa - ((ll)m * (m-1)) / 2;
  }

  cout << res;
  return 0;
}