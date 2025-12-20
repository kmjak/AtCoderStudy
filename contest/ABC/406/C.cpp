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
  int N;cin>>N;
  vi P(N);
  for(int i=0;i<N;i++)cin>>P[i];

  ll res=0;
  string S(N-1,' ');
  for(int i=0;i<N-1;i++){
    if(P[i]<P[i+1]) S[i]='<';
    else S[i]='>';
  }
  cout<<S<<endl;

  int l=0;
  while(l<N-4){
    int r=l+3;
    while(r<N-1){
      string sub = S.substr(l,r-l+1);
      cout<<sub<<endl;
      int a=0;
      int b=0;
      bool flag=true;
      for(int i=0;i<r-l;i++){
        if(sub[i]=='<'){
          if(sub[i+1]=='>'){
            if(a!=0){
              flag=false;
              break;
            }
            a++;
          }
        }

        if(sub[i]=='>'){
          if(sub[i+1]=='<'){
            if(b!=0){
              flag=false;
              break;
            }
            b++;
          }
        }
      }
      if(!flag){
        break;
      }
      if(a==0|| b==0){
        break;
      }
      res++;
      r++;
    }
    l++;
  }
  cout<<res<<endl;
  return 0;
}