// chatgpt o1

#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>

using namespace std;

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

// struct Point {
//     double x;
//     double y;
// };

// int main()
// {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int n;
//   double s, t;
//   cin >> n >> s >> t;

//   vector<pair<int,int>> ab(n), cd(n);
//   rep(i,0,n){
//     cin >> ab[i].first >> ab[i].second >> cd[i].first >> cd[i].second;
//   }

//   int total_pos = 2 * n;
//   vector<Point> pos(total_pos);
//   rep(i,0,n){
//     pos[2*i].x = ab[i].first;
//     pos[2*i].y = ab[i].second;
//     pos[2*i+1].x = cd[i].first;
//     pos[2*i+1].y = cd[i].second;
//   }

//   int MAX_MASK = 1 << n;
//   const double INF = 1e18;
//   vector<vector<double>> dp(MAX_MASK, vector<double>(total_pos, INF));

//   rep(i,0,n){
//     {
//       double dist_move = sqrt( pow(pos[2*i].x - 0.0, 2) + pow(pos[2*i].y - 0.0, 2) );
//       double time_move = dist_move / s;
//       double dist_draw = sqrt( pow(pos[2*i+1].x - pos[2*i].x, 2) + pow(pos[2*i+1].y - pos[2*i].y, 2) );
//       double time_draw = dist_draw / t;
//       double total_time = time_move + time_draw;
//       int new_mask = (1 << i);
//       if (total_time < dp[new_mask][2*i+1]){
//           dp[new_mask][2*i+1] = total_time;
//       }
//     }
//     {
//       double dist_move = sqrt( pow(pos[2*i+1].x - 0.0, 2) + pow(pos[2*i+1].y - 0.0, 2) );
//       double time_move = dist_move / s;
//       double dist_draw = sqrt( pow(pos[2*i].x - pos[2*i+1].x, 2) + pow(pos[2*i].y - pos[2*i+1].y, 2) );
//       double time_draw = dist_draw / t;
//       double total_time = time_move + time_draw;
//       int new_mask = (1 << i);
//       if (total_time < dp[new_mask][2*i]){
//           dp[new_mask][2*i] = total_time;
//       }
//     }
//   }

//   rep(mask, 0, MAX_MASK){
//     rep(last,0,total_pos){
//       if(dp[mask][last] < INF){
//         rep(i,0,n){
//           if( !(mask & (1 << i)) ){
//             {
//               double dist_move = sqrt( pow(pos[2*i].x - pos[last].x, 2) + pow(pos[2*i].y - pos[last].y, 2) );
//               double time_move = dist_move / s;
//               double dist_draw = sqrt( pow(pos[2*i+1].x - pos[2*i].x, 2) + pow(pos[2*i+1].y - pos[2*i].y, 2) );
//               double time_draw = dist_draw / t;
//               double total_time = dp[mask][last] + time_move + time_draw;
//               int new_mask = mask | (1 << i);
//               if (total_time < dp[new_mask][2*i+1]){
//                   dp[new_mask][2*i+1] = total_time;
//               }
//             }
//             {
//               double dist_move = sqrt( pow(pos[2*i+1].x - pos[last].x, 2) + pow(pos[2*i+1].y - pos[last].y, 2) );
//               double time_move = dist_move / s;
//               double dist_draw = sqrt( pow(pos[2*i].x - pos[2*i+1].x, 2) + pow(pos[2*i].y - pos[2*i+1].y, 2) );
//               double time_draw = dist_draw / t;
//               double total_time = dp[mask][last] + time_move + time_draw;
//               int new_mask = mask | (1 << i);
//               if (total_time < dp[new_mask][2*i]){
//                   dp[new_mask][2*i] = total_time;
//               }
//             }
//           }
//         }
//       }
//     }
//   }

//   double answer = INF;
//   int full_mask = (1 << n) -1;
//   rep(last,0,total_pos){
//     if(dp[full_mask][last] < answer){
//       answer = dp[full_mask][last];
//     }
//   }

//   cout << fixed << setprecision(10) << answer;

//   return 0;
// }

using pi=pair<int,int>;

long double dist(pi l, pi r){
  long long v = 0;
  v += (l.first - r.first) * (l.first - r.first);
  v += (r.second - l.second) * (r.second - l.second);
  return sqrt((long double)v);
}

int main()
{
  int n;
  long double s,t;
  cin >> n >> s >> t;
  vector<pi> y(n),x(n);
  rep(i,0,n) cin >> x[i].first >> x[i].second >> y[i].first >> y[i].second;

  vector<int> p;
  long double res = 8e18;

  rep(i,0,n){
    p.pb(i);
  }

  do
  {
    rep(i,0,1<<n){
      long double cres = 0.0;
      pi cur = {0,0};
      rep(j,0,n){
        int el = p[j];
        if(i&(1<<j)){
          cres += dist(cur,x[el]) / s;
          cres += dist(x[el],y[el]) / t;
          cur = y[el];
        }else{
          cres += dist(cur,y[el]) / s;
          cres += dist(y[el],x[el]) / t;
          cur = x[el];
        }
      }
      chmin(res,cres);
    }
  } while (next_permutation(all(p)));

  cout << fixed << setprecision(12) << res << "\n";
  return 0;
}