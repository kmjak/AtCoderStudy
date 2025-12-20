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

int H,W;
pi current;

bool isRange(int x, int y) {
  return 0 <= x && x < H && 0 <= y && y < W;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> H >> W >> current.first >> current.second;
  current.first--;
  current.second--;
  vs Field(H);
  vcin(H, Field);
  int C = 0;
  string S;
  cin >> S;
  repa(x,S){
    // cout << current.first << " " << current.second << '\n';
    if(x == 'L'){
      if(isRange(current.first, current.second - 1) && Field[current.first][current.second - 1] != '#'){
        current.second--;
      }
    }else if(x == 'R'){
      if(isRange(current.first, current.second + 1) && Field[current.first][current.second + 1] != '#'){
        current.second++;
      }
    }else if(x == 'U'){
      if(isRange(current.first - 1, current.second) && Field[current.first - 1][current.second] != '#'){
        current.first--;
      }
    }else if(x == 'D'){
      if(isRange(current.first + 1, current.second) && Field[current.first + 1][current.second] != '#'){
        current.first++;
      }
    }
    if(Field[current.first][current.second] == '@'){
      Field[current.first][current.second] = '.';
      C++;
    }
  }
  cout << current.first + 1<< " " << current.second + 1 << " " << C << '\n';
  return 0;
}