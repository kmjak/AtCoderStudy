#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  vi a(n);
  vi temp;
  ll b, k;
  rep(i,0,n) cin >> a[i];

  rep(i,0,q) {
    cin >> b >> k;
    temp.clear();

    for (int j = 0; j < n; j++) {
      temp.push_back(abs(a[j] - b));
    }

    int selectCount = min(2 * (int)k, n);
    nth_element(temp.begin(), temp.begin() + selectCount, temp.end());
    temp.resize(selectCount);

    sort(temp.begin(), temp.end());

    cout << temp[k-1] << endl;
  }

  return 0;
}