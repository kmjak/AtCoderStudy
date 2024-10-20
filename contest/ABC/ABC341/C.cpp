#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
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

unordered_map<char,int> DX = {
  {'L',-1},
  {'R',1},
  {'U',0},
  {'D',0}
};
unordered_map<char,int> DY = {
  {'L',0},
  {'R',0},
  {'U',-1},
  {'D',1}
};
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // int H,W,N;
  // cin >> H >> W >>N;
  // string S;
  // cin >> S;
  // vector<pi> possible_xy;
  // vector<vector<bool>> Grid(H,vector<bool>(W,false));
  // rep(i,0,H) {
  //   string tmp;
  //   cin >> tmp;
  //   if(i == 0 || i + 1 == H) continue;
  //   rep(j,1,W-1){
  //     if(tmp[j] == '.'){
  //       Grid[i][j] = true;
  //       possible_xy.eb(mp(j,i));
  //     }
  //   }
  // }
  // repa(x,S){
  //   int actx = DX[x];
  //   int acty = DY[x];
  //   // cout << x << ":" << DX[x] << " " << DY[x] << '\n';
  //   // cout << possible_xy.size() << '\n';
  //   // repa(x,possible_xy){
  //   //   cout << x.second+1 << x.first+1 << '\n';
  //   // }
  //   // cout << "-----------------" << '\n';
  //   for(auto it = possible_xy.begin(); it != possible_xy.end(); ) {
  //     auto &[crntx, crnty] = *it;
  //     crntx += actx;
  //     crnty += acty;
  //     if(!Grid[crnty][crntx]){
  //       it = possible_xy.erase(it);
  //     } else {
  //       ++it;
  //     }
  //   }

  // }
  // cout << possible_xy.size() << '\n';


  // int H,W,N;
  // cin >> H >> W >>N;
  // string S;
  // cin >> S;
  // vector<pi> Act(N+1,{0,0});
  // rep(i,0,N){
  //   int actx = DX[S[i]];
  //   int acty = DY[S[i]];
  //   Act[i+1] = mp(Act[i].first+acty,Act[i].second+actx);
  // }
  // vector<pi> possible_xy;
  // vector<vector<bool>> Grid(H,vector<bool>(W,false));
  // rep(i,0,H) {
  //   string tmp;
  //   cin >> tmp;
  //   if(i == 0 || i + 1 == H) continue;
  //   rep(j,1,W-1){
  //     if(tmp[j] == '.'){
  //       Grid[i][j] = true;
  //       possible_xy.pb(mp(i,j));
  //     }
  //   }
  // }

  // int c = possible_xy.size();
  // // repa(x,Act){
  // //   cout << x.first << " " << x.second << '\n';
  // // }
  // repa(x,Act){
  //   for(auto it = possible_xy.begin()+1; it != possible_xy.end();){
  //     auto [cx, cy] = *it;
  //     int nx = cx + x.second;
  //     int ny = cy + x.first;
  //     if(nx < 0 || nx >= H || ny < 0 || ny >= W || !Grid[nx][ny]) {
  //       c--;
  //       it = possible_xy.erase(it);
  //     }else{
  //       it++;
  //     }
  //   }
  // }
  // cout << c << '\n';



  int H,W,N;
  cin >> H >> W >>N;
  string S;
  cin >> S;
  vector<pi> Act(N+1,{0,0});
  rep(i,0,N){
    int actx = DX[S[i]];
    int acty = DY[S[i]];
    Act[i+1] = mp(Act[i].first+acty,Act[i].second+actx);
  }
  vs Grid(H);
  rep(i,0,H) {
    cin >> Grid[i];
  }
  int res = 0;
  rep(i,1,H-1) {
    rep(j,1,W-1) {
      bool f = true;
      repa(x,Act){
        if(Grid[i+x.fi][j+x.se] == '#'){
          f = false;
          break;
        }
      }
      if(f){
        res++;
      }
    }
  }
  cout << res << '\n';


  return 0;
}