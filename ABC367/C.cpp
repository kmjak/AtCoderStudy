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

int n, k;
vi r, current;

void dfs(int index, int sum) {
  if (index == n) {
    if (sum % k == 0) {
      rep(i, 0, n) {
        cout << current[i] << (i == n - 1 ? "\n" : " ");
      }
    }
    return;
  }

  rep(i, 1, r[index] + 1) {
    current[index] = i;
    dfs(index + 1, sum + i);
  }
}

int main() {
  cin >> n >> k;
  r.resize(n);
  current.resize(n);
  rep(i, 0, n) {
    cin >> r[i];
  }
  dfs(0, 0);
  return 0;
}