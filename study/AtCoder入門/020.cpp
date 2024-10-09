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
  // int N;
  // cin >> N;
  // int first_B = 0,last_A = 0,C = 0,FA_LB = 0;
  // rep(i,0,N){
  //   string tmp;
  //   cin >> tmp;
  //   rep(j,0,tmp.size()-1){
  //     if(tmp[j] == 'A' && tmp[j+1] == 'B') C++;
  //   }
  //   if(tmp[0] == 'B') first_B++;
  //   if(tmp[tmp.size()-1] == 'A')last_A++;
  //   if(tmp[tmp.size()-1] == 'A' && tmp[0] == 'B'){
  //     first_B--;
  //     last_A--;
  //     FA_LB++;
  //   }
  // }
  // if(FA_LB > 0){
  //   C += FA_LB-1;
  //   if(first_B > 0){
  //     C++;
  //     first_B--;
  //   }
  //   if(last_A > 0){
  //     C++;
  //     last_A--;
  //   }
  //   FA_LB = 0;
  // }
  // C += min(first_B,last_A);
  // cout << C << endl;
  int N;
  cin >> N;
  int T = 0,C1 = 0,C2 = 0,C3 = 0;
  rep(i,0,N){
    string S;
    cin >> S;

    rep(j,0,S.size()-1){
      if(S[j] == 'A' && S[j+1] == 'B') T++;
    }
    if(S[0] == 'B' && S.back() == 'A') C1++;

    else if(S.back() == 'A') C2++;

    else if(S[0] == 'B') C3++;
  }
  if(C2 || C3) cout << T + C1 + min(C2,C3) << endl;
  else cout << T + max(0,C1-1) << endl;
  return 0;
}
