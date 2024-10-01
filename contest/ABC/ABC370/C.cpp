#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(int i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define repra(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  vs x;

  vector<tuple<size_t, char, char>> temp;

  rep(i, 0, s.size()) {
    if (s[i] != t[i]) {
      temp.push_back(make_tuple(i, t[i], s[i]));
    }
  }

  cout << temp.size() << endl;

  repa(i,temp){
    if(get<1>(i) < get<2>(i)){
      s[get<0>(i)] = get<1>(i);
      cout << s << endl;
    }
  }

  repra(i,temp){
    if(get<1>(*i) > get<2>(*i)){
      s[get<0>(*i)] = get<1>(*i);
      cout << s << endl;
    }
  }

  return 0;
}