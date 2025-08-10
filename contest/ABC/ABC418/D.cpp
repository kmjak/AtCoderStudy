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
 * 考察1
 * l<rのとき、
 * その区間の0が偶数この時、美しい文字列となる
 * 理由としては以下の例を用いて行う
 * 例: 000
 * - 000
 * 00 -> 1
 * - 10
 * 10 -> 0
 *
 * 例: 0010010
 * - 0010010
 * 00 -> 1
 * - 110010
 * 10 -> 0
 * - 10010
 * 10 -> 0
 * - 0010
 * 00 -> 1
 * - 110
 * 10 -> 0
 * - 10
 * このように0が奇数個だと美しくなくなくなる
 *
 * よって、0の累積和を取り
 * 0<=i<j<=Nの条件で
 * (sum[j]-sum[i])%2==0の時、美しいと言える
 * 問題としては(N+1)*N/2通りになるので時間的に無理そう
 *
 * 考察2
 * 考察1の通り、美しい文字列の条件は
 * (sum[j]-sum[i])%2==0である
 * 言い換えればsum[i]とsum[j]の偶奇が一致するかどうか
 *
 * なので、0<=i<=Nにおけるsum[i]の偶奇を調べ
 * 偶数の個数をc0、奇数の個数をc1とする
 * 偶数同士の組合せc0*(c01)/2 + 奇数同士の組合せc1*(c1-1)/2
 * が答えになる
 */

ll N;
string T;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>T;
  ll c0=1;
  ll c1=0;
  ll sum=0;
  for(ll i=0;i<N;i++){
    sum+=(T[i]=='0');
    c0+=(sum%2==0);
    c1+=(sum%2==1);
  }
  ll res=c0*(c0-1)/2+c1*(c1-1)/2;
  cout<<res<<endl;
  return 0;

}