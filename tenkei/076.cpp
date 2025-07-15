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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll N;
  cin>>N;
  vll A(N);
  ll total=0;
  for(ll i=0;i<N;i++) {
    cin>>A[i];
    total+=A[i];
  }

  if(total%10!=0) {
    cout<<"No"<<endl;
    return 0;
  }

  ll tg=total/10;
  ll l=0;
  ll r=0;
  ll cur=0;

  bool ok=false;
  while(l<N*2){
    if(cur==tg) {
      ok=true;
      break;
    }else if(cur>tg) {
      cur-=A[l%N];
      l++;
    }else{
      if(cur==N) {
        break;
      }
      cur+=A[r%N];
      r++;
    }
  }
  cout<<(ok?"Yes":"No")<<endl;
  return 0;
}