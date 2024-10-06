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
  // int H,W,N;
  // cin >> H >> W >> N;
  // vvi field(H,vi(W,0));
  // while(N--){
  //   pi l,r;
  //   cin >> l.first >> l.second >> r.first >> r.second;
  //   rep(i,l.first-1,r.first){
  //     rep(j,l.second-1,r.second){
  //       field[i][j]++;
  //     }
  //   }
  // }
  // repa(x,field){
  //   repa(y,x) cout << y << " ";
  //   cout << endl;
  // }

  // int H,W,N;
  // cin >> H >> W >> N;
  // vector<pi> l_snows(N),r_snows(N);
  // rep(i,0,N){
  //   pi l,r;
  //   cin >> l.first >> l.second >> r.first >> r.second;
  //   l.first--;
  //   l.second--;
  //   r.first--;
  //   r.second--;
  //   l_snows[i] = l;
  //   r_snows[i] = r;
  // }
  // rep(i,0,N){
  //   rep(j,0,H){
  //     int sum = 0;
  //     if(l_snows[i].first > j) continue;
  //     if(r_snows[i].first < j) break;
  //     rep(k,0,W){
  //       if(l_snows[k].second > j) continue;
  //       if(r_snows[k].second < j) break;
  //       sum++;
  //     }
  //   }
  // }
  // rep(i,0,H){
  //   rep(j,0,W){
  //     int sum = 0;
  //     rep(k,0,N){
  //       if(l_snows[k].first <= i && r_snows[k].first >= i && l_snows[k].second <= j && r_snows[k].second >= j) sum++;
  //     }
  //     cout << sum << " ";
  //   }
  //   cout << endl;
  // }
  int H,W,N;
  cin >> H >> W >> N;
  vvi field(H,vi(W+2,0));
  while(N--){
    pi l,r;
    cin >> l.first >> l.second >> r.first >> r.second;
    l.first--;
    r.second++;
    rep(i,l.first,r.first){
      field[i][l.second]++;
      field[i][r.second]--;
    }
  }
  rep(i,0,H){
    int sum = 0;
    rep(j,1,W+1){
      sum += field[i][j];
      cout << sum << " ";
    }
    cout << endl;
  }
  return 0;
}