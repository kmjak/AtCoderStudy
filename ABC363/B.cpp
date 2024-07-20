#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  int n,t,p;
  cin >> n >> t >> p;
  vi l(n);
  rep(0,n){
    cin >> l[i];
  }
  sort(l.begin(),l.end(),greater<int>());
  p--;
  if(l[p] > t){
    cout << 0 << endl;
    return 0;
  }
  cout << abs(t - l[p]) << endl;

  return 0;
}