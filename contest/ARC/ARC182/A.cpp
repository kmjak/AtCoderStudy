#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define rrep(i,s,n) for(int i = s; i >= n; i--)
#define repauto(i, x) for(auto i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
int main()
{
  int n,q;
  cin >> n >> q;
  vi p(q),v(q);
  rep(i,0,q){
    cin >> p[i] >> v[i];
  }
  vi pattern(q,0);
  bool flag;
  ll c = 0;
  rep(i,0,pow(2,q)){
    vi s(n,0);
    bool f = true;
    rep(j,0,q){
      if(pattern[j] == 0){
        flag = true;
        rep(k,0,p[j]){
          if(s[k] > v[j]){
            flag = false;
            f = false;
            break;
          }
        }
        if(flag){
          rep(k,0,p[j]){
            s[k] = v[j];
          }
        }else{
          break;
        }
      }
      if(pattern[j] == 1){
        flag = true;
        rep(k,p[j],n){
          if(s[k] > v[j]){
            flag = false;
            f = false;
            break;
          }
        }
        if(flag){
          rep(k,p[j],n){
            s[k] = v[j];
          }
        }else{
          break;
        }
      }
    }
    if(f){
      c++;
    }
    pattern[0]++;
    rep(j,0,q){
      if(pattern[j] == 2){
        pattern[j] = 0;
        pattern[j+1]++;
      }
    }
  }
  cout << c << endl;
  return 0;
}