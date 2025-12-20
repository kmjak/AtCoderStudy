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

int main()
{
  int m;
  cin >> m;
  vi A(11);
  vi ans;

  A[0] = 1;
  A[1] = 3;
  rep(i, 2, 11){
    A[i] = A[i - 1] * 3;
  }


  int j = 10;
  while(m > 0){
    rrep(i, j, 0){
      if(m >= A[i]){
        ans.push_back(i);
        m -= A[i];
        j = i;
        break;
      }
    }
  }

  cout << ans.size() << endl;
  for(int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }

  return 0;
}