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
  while (T--) {
    int N;cin>>N;
    vll A(N);
    for (int i = 0; i < N; i++)cin>>A[i];
    bool f = true;
    sort(all(A), [](ll a, ll b){ return abs(a) < abs(b); });

    if(abs(A[0]) == abs(A[N-1])){
      int p=0;
      int m=0;
      for(int i=0;i<N;i++){
        if(A[i] > 0) p++;
        else if(A[i] < 0) m++;
      }
      if(p!=0&&m!=0&&abs(p-m) > 1){
        f = false;
      }
    }else{
      for(int i=2;i<N;i++){
        if(A[i-1]*A[i-1]!=A[i-2]*A[i]){
          f = false;
          break;
        }
      }
    }
    cout << (f ? "Yes" : "No") << '\n';
  }

  return 0;
}