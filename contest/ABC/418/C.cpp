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

class SegmentTreeRMQ {
  public:
  vll data;
  ll size = 1;

  void init(ll n){
    while(size < n) size *= 2;
    data.assign(size * 2, 0);
  }

  void update(ll pos, ll x){
    pos += size - 1;
    data[pos] = x;
    while(pos >= 2){
      pos /= 2;
      data[pos] = max(data[pos*2], data[pos*2+1]);
    }
  }

  ll query(ll l, ll r, ll bl, ll br, ll u){
    if(r <= bl || br <= l)return -1e18;
    if(l <= bl && br <= r)return data[u];
    ll m = (bl + br) / 2;
    ll al = query(l, r, bl, m, u*2);
    ll ar= query(l, r, m, br, u*2+1);
    return max(al, ar);
  }
};

class SegmentTreeRSQ {
  public:
  vll data;
  ll size = 1;

  void init(ll n){
    while(size < n) size *= 2;
    data.assign(size * 2, 0);
  }

  void update(ll pos, ll x){
    pos += size - 1;
    data[pos] = x;
    while(pos >= 2){
      pos /= 2;
      data[pos] = data[pos*2] + data[pos*2+1];
    }
  }

  ll query(ll l, ll r, ll bl, ll br, ll u){
    if(r <= bl || br <= l)return 0;
    if(l <= bl && br <= r)return data[u];
    ll m = (bl + br) / 2;
    ll al = query(l, r, bl, m, u*2);
    ll ar= query(l, r, m, br, u*2+1);
    return al + ar;
  }
};

bool isRange(ll x, ll y, ll w, ll h){
  return (0 <= x && x < w) && (0 <= y && y < h);
}

vll dx={1, 0, -1, 0};
vll dy={0, 1, 0, -1};
const ll MOD=1e9+7;

/**
 * 考察
 * ノートで実際に動きを考察してたまたま解けた！
 * ノートでたどり着いた解法
 * b + sum(0,l-1) + (N-L-1) * (b-1)
 *
 * これが成り立つ理由は
 *
 * 1. まず、最終的にxの中からb個取り出し、それが同じである必要があるのでb個必要
 *
 * 2. 次に、0からl-1までの累積和を取る
 * 理由としては、bよりも大きい最小の数がlだから、
 * それ以下はどれだけ取り出しても意味がない。
 * つまり、全部選択される。
 * なので、sum(0,l-1)
 *
 * 3. 最後に、l+1からNまでの数はb-1個選択される。
 * なので、(N-l-1) * (b-1)
 *
 * それらを足し合わせると
 * b + sum(0,l-1) + (N-l-1) * (b-1)
 * となる
 *
 * ただし、Aの中で最大の数よりもbが大きい場合は、
 * そのような数は存在しないので-1を出力
 */
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N,Q;cin>>N>>Q;
  vll A(N);
  vll sum(N+1);
  for(ll i=0;i<N;i++){
    cin>>A[i];
  }

  sort(all(A));
  for(ll i=0;i<N;i++){
    sum[i+1]=sum[i]+A[i];
  }
  while(Q--){
    ll b;cin>>b;
    ll l=lower_bound(all(A), b) - A.begin();
    if(l==N){
      cout<<-1<<endl;
      continue;
    }
    cout<<b+sum[l+1]-A[l]+(N-l-1)*(b-1)<<endl;
  }
  return 0;
}