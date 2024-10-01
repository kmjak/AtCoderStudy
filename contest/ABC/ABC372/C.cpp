#include <bits/stdc++.h>

#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define vvs vector<vs>
#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

bool isABC(const string& s, int i) {
  if (i < 0 || i + 2 >= s.size()) return false;
  return (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C');
}

int main()
{
  int n, q;
  string s;
  cin >> n >> q >> s;
  vi ans(q);

  int abc = 0;
  rep(i, 0, n - 2) {
    if (isABC(s, i)) abc++;
  }

  rep(i, 0, q) {
    int x;
    char c;
    cin >> x >> c;
    x--;

    for (int j = x - 2; j <= x; j++) {
      if (isABC(s, j)) abc--;
    }

    s[x] = c;

    for (int j = x - 2; j <= x; j++) {
      if (isABC(s, j)) abc++;
    }

    ans[i] = abc;
  }

  repa(i, ans) {
    cout << i << endl;
  }

  return 0;
}