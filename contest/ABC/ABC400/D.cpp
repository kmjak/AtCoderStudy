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
  pi ignore;

  bool operator<(const pnt &p) const {
    if (x == p.x) return y < p.y;
    return x < p.x;
  }
};

int H,W;
vs G(1010);
vi dx={1,0,-1,0};
vi dy={0,1,0,-1};
vvi score(1010,vi(1010,INT_MAX));
priority_queue<pair<int, pnt>, vector<pair<int, pnt>>, greater<pair<int, pnt>>> pq;
pnt st;
pnt gl;

bool isRange(int x, int y) {
  return (x >= 0 && x < W&& y >= 0 && y < H);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>H>>W;
  for(int i=0;i<H;i++){
    cin>>G[i];
  }
  cin>>st.y>>st.x>>gl.y>>gl.x;
  st.y--;
  st.x--;
  gl.y--;
  gl.x--;

  score[st.y][st.x]=0;
  pq.push({0,{st.x,st.y,mp(-1,-1)}});
  while(!pq.empty()){
    auto [s,p]=pq.top();
    pq.pop();
    int x=p.x;
    int y=p.y;
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(!isRange(nx,ny))continue;
      if(score[ny][nx] <= s)continue;
      if(G[ny][nx]=='#'&&(p.ignore.first!=nx||p.ignore.second!=ny)){
        score[ny][nx]=s+1;
        pq.push({s+1,{nx,ny,mp(nx+dx[i],ny+dy[i])}});
      }else{
        score[ny][nx]=s;
        pq.push(mp(s,pnt{nx,ny,mp(-1,-1)}));
      }
    }
  }

  // for(int i=0;i<H;i++){
  //   for(int j=0;j<W;j++){
  //     cout<<score[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  cout<<score[gl.y][gl.x]<<endl;
  return 0;
}