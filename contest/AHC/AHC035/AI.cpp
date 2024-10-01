#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vint vector<int>
#define vvi vector<vector<int>>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

const int N = 6;
const int M = 15;
const int T = 10;
const int SEED_COUNT = 2 * N * (N - 1);

struct Seed {
  vi x;
  int value;
  int index;
};

int calculateValue(const vi& x) {
  return accumulate(x.begin(), x.end(), 0);
}

int main() {
  int n, m, t;
  cin >> n >> m >> t;

  vector<Seed> seeds(SEED_COUNT);

  rep(i, 0, SEED_COUNT) {
    seeds[i].x.resize(M);
    rep(j, 0, M) {
      cin >> seeds[i].x[j];
    }
    seeds[i].value = calculateValue(seeds[i].x);
    seeds[i].index = i;
  }

  rep(turn, 0, T) {
    sort(seeds.begin(), seeds.end(), [](const Seed& a, const Seed& b) {
      return a.value > b.value;
    });

    vvi field(N, vi(N));
    rep(i, 0, N) {
      rep(j, 0, N) {
        field[i][j] = seeds[i * N + j].index;
        cout << field[i][j];
        if(j < N - 1) {
          cout << " ";
        } else {
          cout << endl;
        }
      }
    }
    cout << flush;

    rep(i, 0, SEED_COUNT) {
      rep(j, 0, M) {
        cin >> seeds[i].x[j];
      }
      seeds[i].value = calculateValue(seeds[i].x);
      seeds[i].index = i;
    }
  }

  return 0;
}