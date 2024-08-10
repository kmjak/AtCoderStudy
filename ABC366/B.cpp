#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  int max_len = 0;
  
  rep(i, 0, n) {
    cin >> s[i];
    max_len = max(max_len, (int)s[i].size());
  }

  vector<string> T(max_len, string(n, '*'));

  rep(i, 0, n) {
    int len = s[i].size();
    rep(j, 0, len) {
      T[j][n-1-i] = s[i][j];
    }
  }

  rep(i, 0, max_len) {
    while (T[i].back() == '*') {
      T[i].pop_back();
    }
  }

  rep(i, 0, max_len) {
    cout << T[i] << endl;
  }

  return 0;
}