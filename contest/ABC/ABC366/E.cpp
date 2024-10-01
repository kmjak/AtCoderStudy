// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vll vector<ll>
// #define rep(i,s,n) for(int i = s; i < n; i++)
// using namespace std;
// int main()
// {
//   int n,d;
//   int c = 0;
//   cin >> n >> d;
//   vi x(n), y(n);
//   rep(i, 0, n) {
//     cin >> x[i] >> y[i];
//   }
//   sort(x.begin(), x.end());
//   sort(y.begin(), y.end());
//   rep(i,0,n){
//     rep(j,0,n){
//       if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= d){
//         c++;
//       }else{
//         break;
//       }
//     }
//   }
//   cout << c << endl;
//   return 0;
// }
// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define rep(i,s,n) for(int i = s; i < n; i++)
// using namespace std;

// int main() {
//   int n, d;
//   cin >> n >> d;
//   vi x(n), y(n);
//   int minx = INT_MAX, maxx = INT_MIN;
//   int miny = INT_MAX, maxy = INT_MIN;
  
//   rep(i, 0, n) {
//     cin >> x[i] >> y[i];
//     minx = min(minx, x[i]);
//     maxx = max(maxx, x[i]);
//     miny = min(miny, y[i]);
//     maxy = max(maxy, y[i]);
//   }
  
//   int c = 0;
//   for (int X = minx - d; X <= maxx + d; X++) {
//     for (int Y = miny - d; Y <= maxy + d; Y++) {
//       int dist_sum = 0;
//       rep(i, 0, n) {
//         dist_sum += abs(X - x[i]) + abs(Y - y[i]);
//       }
//       if (dist_sum <= d) {
//         c++;
//       }
//     }
//   }

//   cout << c << endl;
//   return 0;
// }
#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vi x(n), y(n);
  int minx = INT_MAX, maxx = INT_MIN;
  int miny = INT_MAX, maxy = INT_MIN;
  
  rep(i, 0, n) {
    cin >> x[i] >> y[i];
    minx = min(minx, x[i]);
    maxx = max(maxx, x[i]);
    miny = min(miny, y[i]);
    maxy = max(maxy, y[i]);
  }
  
  int c = 0;
  for (int X = minx - d; X <= maxx + d; X++) {
    for (int Y = miny - d; Y <= maxy + d; Y++) {
      int dist_sum = 0;
      rep(i, 0, n) {
        dist_sum += abs(X - x[i]) + abs(Y - y[i]);
        if(dist_sum > d) break; 
      }
      if (dist_sum <= d) {
        c++;
      }
    }
  }

  cout << c << endl;
  return 0;
}