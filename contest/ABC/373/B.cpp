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
#define repra(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int main() {
  string S;
  cin >> S;

  unordered_map<char, int> k;
  rep (i,0,26) {
    k[S[i]] = i + 1;
  }

  int ans = 0;
  int prev = k['A'];

  for (char c = 'B'; c <= 'Z'; c++) {
    int n = k[c];
    ans += abs(n - prev);
    prev = n;
  }

  cout << ans << endl;

  return 0;
}