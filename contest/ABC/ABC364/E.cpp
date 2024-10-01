#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;

int main() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<pair<ll, ll>> a;
  vector<pair<ll, ll>> b;

  rep(i, 0, n) {
    ll key, value;
    cin >> key >> value;
    a.push_back(make_pair(key, value));
    b.push_back(make_pair(key, value));
  }

  sort(a.begin(), a.end(), [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
    return p1.first < p2.first;
  });

  sort(b.begin(), b.end(), [](const pair<ll, ll>& p1, const pair<ll, ll>& p2) {
    return p1.second < p2.second;
  });
  int c1 = 0;
  int c2 = 0;
  int A1_sum = 0;
  int B1_sum = 0;
  int A2_sum = 0;
  int B2_sum = 0;
  rep(i, 0, n) {
    c1++;
    if (A1_sum + a[i].first > x) {
      break;
    }
    if (B1_sum + a[i].second > y) {
      while(true){
        i++;
        if(A1_sum + a[i].first > x){
          return 0;
        }
        if(B1_sum + a[i].second < y){
          break;
        }
      }
    }
    A1_sum += a[i].first;
    B1_sum += a[i].second;
  }
  rep(i, 0, n) {
    c2++;
    if (A2_sum + b[i].first > x) {
      break;
    }
    if (B2_sum + b[i].second > y) {
      while(true){
        i++;
        if(A2_sum + b[i].first > x){
          return 0;
        }
        if(B2_sum + b[i].second < y){
          break;
        }
      }
    }
    A2_sum += b[i].first;
    B2_sum += b[i].second;
  }
  cout << max(c1, c2) << endl;
  return 0;
}