// #include <bits/stdc++.h>
// #define ll long long int
// #define vi vector<int>
// #define vll vector<ll>
// #define rep(i,s,n) for(int i = s; i < n; i++)
// using namespace std;

// int main() {
//   int n, q;
//   cin >> n;
//   vector<vector<vector<int>>> a(n, vector<vector<int>>(n, vector<int>(n)));

//   rep(i, 0, n) {
//     rep(j, 0, n) {
//       rep(k, 0, n) {
//         cin >> a[i][j][k];
//       }
//     }
//   }

//   cin >> q;
//   vi ans(q);
//   rep(i, 0, q) {
//     int lx, rx, ly, ry, lz, rz;
//     cin >> lx >> rx >> ly >> ry >> lz >> rz;
//     lx--;
//     rx--;
//     ly--;
//     ry--;
//     lz--;
//     rz--;

//     ll sum = 0;
//     rep(x, lx, rx + 1) {
//       rep(y, ly, ry + 1) {
//         rep(z, lz, rz + 1) {
//           sum += a[x][y][z];
//         }
//       }
//     }
//     ans[i] = sum; 
//   }
//   rep(i, 0, q) {
//     cout << ans[i] << endl;
//   }

//   return 0;
// }


#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  int n, q;
  cin >> n;
  vector<vector<vector<ll>>> a(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));

  rep(i, 1, n + 1) {
    rep(j, 1, n + 1) {
      rep(k, 1, n + 1) {
        cin >> a[i][j][k];
        a[i][j][k] += a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1] 
                    - a[i-1][j-1][k] - a[i-1][j][k-1] - a[i][j-1][k-1]
                    + a[i-1][j-1][k-1];
      }
    }
  }

  cin >> q;
  vi ans(q);
  rep(i, 0, q) {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;

    lx--; ly--; lz--;

    ll sum = a[rx][ry][rz] 
           - (lx > 0 ? a[lx][ry][rz] : 0)
           - (ly > 0 ? a[rx][ly][rz] : 0)
           - (lz > 0 ? a[rx][ry][lz] : 0)
           + (lx > 0 && ly > 0 ? a[lx][ly][rz] : 0)
           + (lx > 0 && lz > 0 ? a[lx][ry][lz] : 0)
           + (ly > 0 && lz > 0 ? a[rx][ly][lz] : 0)
           - (lx > 0 && ly > 0 && lz > 0 ? a[lx][ly][lz] : 0);

    ans[i] = sum; 
  }

  rep(i, 0, q) {
    cout << ans[i] << endl;
  }

  return 0;
}