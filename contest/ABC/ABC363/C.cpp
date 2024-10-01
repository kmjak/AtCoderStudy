#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;

bool containsPalindrome(const string& s, int k) {
  for (int i = 0; i <= s.size() - k; ++i) {
    bool flag = true;
    for (int j = 0; j < k/ 2; ++j) {
      if (s[i + j] != s[i + k - 1 - j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;

  sort(s.begin(), s.end());
  int c = 0;

  do {
    if (!containsPalindrome(s, k)) {
      c++;
    }
  } while (next_permutation(s.begin(), s.end()));

  cout << c << endl;

  return 0;
}