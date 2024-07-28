#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(i,s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
  ll n,x,y;
  cin >> n >> x >> y;
  vll A(n),B(n);
  rep(i,0,n) cin >> A[i];
  rep(i,0,n) cin >> B[i];
  sort(A.rbegin(), A.rend());
  sort(B.rbegin(), B.rend());
  ll c = 0;
  ll A_sum = 0;
  ll B_sum = 0;
  rep(i,0,n){
    c++;
    if(A_sum + A[i] > x){
      break;
    }
    if(B_sum + B[i] > y){
      break;
    }
    A_sum += A[i];
    B_sum += B[i];
  }
  cout << c << endl;
  return 0;
}