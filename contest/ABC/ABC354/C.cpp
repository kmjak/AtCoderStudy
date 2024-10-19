#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> cards(n),costs(n);
//     for(int i = 0; i < n; i++){
//         cin >> cards.at(i);
//         cin >> costs.at(i);
//     }
//     vector<int> c;
//     for(int i = 0; i < n; i++){
//         bool flag = true;
//         for(int j = 0; j < n; j++){
//             if(cards.at(i) > cards.at(j) && costs.at(i) < costs.at(j)){
//                 flag = false;
//             }
//         }
//         if(flag){
//             c.push_back(i+1);
//         }
//     }
//     cout << c.size() << endl;
//     for(auto x : c){
//         cout << x << " ";
//     }
// }

#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

using ll=long long int;
using pi=pair<int,int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;

using vvi=vector<vi>;
using vvll=vector<vll>;

template<typename T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  vector<tuple<int,int,int>> Cards(N);
  rep(i,0,N){
    int a,c;
    cin >> a >> c;
    Cards[i] = make_tuple(c,a,i);
  }
  sort(all(Cards));

  vi index;
  int v = 0;
  rep(i,0,N){
    if(get<1>(Cards[i]) > v){
      v = get<1>(Cards[i]);
      index.pb(get<2>(Cards[i]));
    }
  }
  
  cout << index.size() << endl;
  sort(all(index));
  repa(x,index) cout << x + 1 << " ";
  cout << endl;
  return 0;
}