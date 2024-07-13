#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i, s, n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vi l(n), r(n);
  rep(i, 0, n) {
    cin >> l[i] >> r[i];
  }

  ll l_sum = accumulate(l.begin(), l.end(), 0LL);
  if (l_sum > 0) {
    cout << "No" << endl;
    return 0;
  }

  ll r_sum = accumulate(r.begin(), r.end(), 0LL);
  vi temp = l;
  if (r_sum >= 0) {
    ll a = abs(l_sum);
    rep(i, 0, n) {
      if (a <= (r[i] - l[i])) {
        temp[i] = l[i] + a;
        a = 0;
        break;
      } else {
        temp[i] = r[i];
        a -= (r[i] - l[i]);
      }
    }
    if (a == 0) {
      cout << "Yes" << endl;
      rep(i, 0, n) {
        cout << temp[i] << " ";
      }
      cout << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}