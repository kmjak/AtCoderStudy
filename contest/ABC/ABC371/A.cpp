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

int main()
{
  int a = 0;
  int b = 0;
  int c = 0;

  rep(i, 0, 3){
    char x;
    cin >> x;
    if(i == 0){
      if(x == '<') b++;
      else a++;
    }
    if(i == 1){
      if(x == '<') c++;
      else b++;
    }
    if(i == 2){
      if(x == '<') c++;
      else a++;
    }
  }
  vector<char> v(3);
  v[a] = 'A';
  v[b] = 'B';
  v[c] = 'C';
  cout << v[1] << endl;
}