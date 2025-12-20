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

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl
#define END cout << '\n'

#define vcin(N,A) rep(i,0,N) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ');

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

struct point {
  ll x;
  ll y;
};

ll N,M;
point current;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> current.x >> current.y;
  current.x--;
  current.y--;
  ll res = 0;
  map<ll, vector<ll>> unvisited_x;
  map<ll, vector<ll>> unvisited_y;
  vector<point> house(N);
  rep(i, 0, N) {
    cin >> house[i].x >> house[i].y;
    house[i].x--;
    house[i].y--;
    unvisited_x[house[i].y].push_back(house[i].x);
    unvisited_y[house[i].x].push_back(house[i].y);
  }
  repa(x, unvisited_x) {
    sort(all(x.second));
  }
  repa(y, unvisited_y) {
    sort(all(y.second));
  }
  while (M--) {
    char c;
    ll move;
    cin >> c >> move;
    if(c == 'U'){
      repa(x,unvisited_y[current.x]){
        if(x > current.y && x <= current.y + move){
          if(count(all(house),point({current.x,current.y + move}))){
            res++;
            house.erase(find(all(house),point({current.x,current.y + move})));
          }
        }
      }
    }else if(c == 'D'){
      repa(x,unvisited_y[current.x]){
        if(x < current.y && x >= current.y - move){
          if(count(all(house),point({current.x,current.y - move}))){
            res++;
            house.erase(find(all(house),point({current.x,current.y - move})));
          }
        }
      }
    }else if(c == 'R'){
      repa(y,unvisited_x[current.y]){
        if(y > current.x && y <= current.x + move){
          if(count(all(house),point({current.x + move,current.y}))){
            res++;
            house.erase(find(all(house),point({current.x + move,current.y})));
          }
        }
      }

    }else if(c == 'L'){
      repa(y,unvisited_x[current.y]){
        if(y < current.x && y >= current.x - move){
          if(count(all(house),point({current.x - move,current.y}))){
            res++;
            house.erase(find(all(house),point({current.x - move,current.y})));
          }
        }
      }
    }
  }
  cout << current.x + 1 << " " << current.y + 1 << '\n';
  return 0;
}