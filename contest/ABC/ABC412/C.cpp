#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

struct pnt {
  ll x;
  ll y;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;cin>>T;
  vll res(T);
  for(int t=0;t<T;t++){
    ll N;cin>>N;
    vll D(N);
    for(ll i=0;i<N;i++) cin>>D[i];

    ll curRes=2;
    ll curMax=D[0] * 2;
    sort(D.begin()+1,D.end()-1);

    int i = 1;
    while (curMax<D[N-1]) {
      ll c = -1;
      while (i<=N-2&&D[i]<=curMax) {
        c=D[i];
        i++;
      }
      if(c==-1) {
        curRes = -1;
        break;
      }
      curRes++;
      curMax=c*2;
    }

    if (curMax < D[N - 1]) {
      curRes = -1;
    }

    res[t] = curRes;
  }
  for(int t=0;t<T;t++){
    cout<<res[t]<<endl;
  }
  return 0;
}