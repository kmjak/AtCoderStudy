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


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // int N,M;
  // cin >> N >> M;
  // vvi V(M+1);
  // V[M].pb(0);
  // rep(i,0,N) {
  //   int d,v;
  //   cin >> d >> v;
  //   rep(j,0,M) {
  //     if(M - d >= j){
  //       V[j].pb(v);
  //     }
  //   }
  // }
  // if(N == 1){
  //   if(V[0].size() == 2){
  //     cout << V[0].back() << '\n';
  //   }else{
  //     cout << 0 << '\n';
  //   }
  //   return 0;
  // }
  // rep(i,0,M) {
  //   sort(all(V[i]));
  // }
  // ll res = 0;
  // rep(i,0,M+1) {
  //   int max = V[i].back();
  //   res += max;
  //   // cout << max << '\n';
  //   if(V[i+1].size() == 0) break;
  //   int j = 1;
  //   while(count(all(V[i]),max) == count(all(V[i+j]),max) && V[i+j].size()){
  //     V[i+j].pop_back();
  //     j++;
  //   }
  // }
  // cout << res << '\n';
  // return 0;

  int N, M;
  cin >> N >> M;
  vvi A(M+1);
  rep(i,0,N) {
    int a,b;
    cin >> a >> b;
    if(a>M){
      continue;
    }
    A[a].pb(b);
  }

  ll res = 0;

  priority_queue<ll> que;

  repa(x,A) {
    repa(y,x) {
      que.push(y);
    }
    if(!que.empty()){
      res += que.top();
      que.pop();
    }
  }
  cout << res << '\n';
}