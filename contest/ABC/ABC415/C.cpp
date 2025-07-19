#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toll(s) stoll(s)
#define btoi(b) static_cast<ll>(b.to_ulong())

using namespace std;

using ll=long long int;
using qll=queue<ll>;
using dq=deque<ll>;

using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

void dfs(vb used, ll unused, ll n, ll score, string s, bool &ok)
{
  if(unused==0||ok){
    ok=true;
    return;
  }
  for(ll i=0;i<n;i++){
    if(!used[i]&&s[score+i]=='0'){
      used[i]=true;
      dfs(used, unused-1, n, score+i, s, ok);
      used[i]=false;
      if(ok) return;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll T;cin>>T;
  while(T--){
    ll N;
    string S;
    cin>>N>>S;
    ll M=1<<N;

    vb bitDp(M, false);
    bitDp[0]=true;
    for (ll i = 1; i < M; i++)bitDp[i]=(S[i-1] == '0');

    vb vis(M,false);
    vis[0] = true;
    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
      ll cur = q.front();q.pop();
      for(ll i=0;i<N;i++){
        ll nx = cur|(1<<i);
        if(!vis[nx]&&bitDp[nx]){
          vis[nx] = true;
          q.push(nx);
        }
      }
    }
    cout<<(vis[M-1] ? "Yes":"No")<<endl;
  }
  return 0;
}