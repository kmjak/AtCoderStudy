#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define rrep(i,s,n) for(int i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int main()
{
  int h, w, q;
  cin >> h >> w >> q;
  vi R(q), C(q);
  vvi wall(h, vi(w, 0));

  rep(i, 0, q) {
    cin >> R[i] >> C[i];
    R[i]--;
    C[i]--;
  }

  rep(i, 0, q) {
    if (wall[R[i]][C[i]] == 0) {
      wall[R[i]][C[i]] = 1;
    } else {
      bool flag1 = false;
      bool flag2 = false;
      rep(j, R[i], h) {
        if (wall[j][C[i]] == 0) {
          wall[j][C[i]] = 1;
          flag1 = true;
          break;
        }
      }
      rep(j, C[i], w) {
        if (wall[R[i]][j] == 0) {
          wall[R[i]][j] = 1;
          flag2 = true;
          break;
        }
      }

      flag1 = false;
      flag2 = false;
      rrep(j, R[i] - 1, 0) {
        if (wall[j][C[i]] == 0) {
          wall[j][C[i]] = 1;
          flag1 = true;
          break;
        }
      }
      rrep(j, C[i] - 1, 0) {
        if (wall[R[i]][j] == 0) {
          wall[R[i]][j] = 1;
          flag2 = true;
          break;
        }
      }
    }
  }

  int c = 0;
  repa(w, wall) {
    c += count(all(w), 0);
  }
  cout << c << endl;

  return 0;
}


//正解
// #include <cassert>
// #include <iostream>
// #include <set>
// #include <vector>
// using namespace std;

// int main() {
//   cin.tie(nullptr);
//   ios::sync_with_stdio(false);

//   int H, W, Q;
//   cin >> H >> W >> Q;

//   vector<set<int>> g1(H), g2(W);
//   for (int i = 0; i < H; i++) {
//     for (int j = 0; j < W; j++) {
//       g1[i].insert(j);
//       g2[j].insert(i);
//     }
//   }

//   auto erase = [&](int i, int j) { g1[i].erase(j), g2[j].erase(i); };

//   while (Q--) {
//     int R, C;
//     cin >> R >> C;
//     --R, --C;

//     if (g1[R].count(C)) {
//       erase(R, C);
//       continue;
//     }

//     // 上
//     {
//       auto it = g2[C].lower_bound(R);
//       if (it != begin(g2[C])) erase(*prev(it), C);
//     }
//     // 下
//     {
//       auto it = g2[C].lower_bound(R);
//       if (it != end(g2[C])) erase(*it, C);
//     }
//     // 左
//     {
//       auto it = g1[R].lower_bound(C);
//       if (it != begin(g1[R])) erase(R, *prev(it));
//     }
//     // 右
//     {
//       auto it = g1[R].lower_bound(C);
//       if (it != end(g1[R])) erase(R, *it);
//     }
//   }

//   int ans = 0;
//   for (int i = 0; i < H; i++) ans += g1[i].size();
//   cout << ans << "\n";
// }
