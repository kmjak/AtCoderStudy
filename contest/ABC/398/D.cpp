#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

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

int R,C;

int randInt(int l, int r) {
  return l + rand() % (r - l + 1);
}

int getDy(char c)
{
  if(c=='N')return -1;
  else if(c=='S') return 1;
  return 0;
}

int getDx(char c)
{
  if(c=='W')return -1;
  else if(c=='E') return 1;
  return 0;
}

bool isSmoke(int x, int y)
{
  return C==x&&y==R;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  string S;
  cin>>N>>R>>C>>S;
  int X=0;
  int Y=0;
  vector<pair<int,int>> smoke;
  smoke.eb(mp(0,0));
  int i=0;
  for(auto c:S){
    int x=getDx(c);
    int y=getDy(c);
    for(int j=0;j<=i;j++){
      smoke[j]=mp(smoke[j].first+x,smoke[j].second+y);
    }
    smoke.eb(mp(0,0));
    bool isTrue=false;
    for(auto s:smoke){
      if(isSmoke(s.first,s.second)){
        cout<<1;
        isTrue=true;
        break;
      }
    }
    if(!isTrue){
      cout<<0;
    }
    i++;
  }
  cout<<endl;
  return 0;
}