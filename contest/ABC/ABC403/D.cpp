#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

#define bs(A,X) binary_search(all(A),X)
#define lbs(A,X) lower_bound(all(A),X)
#define ubs(A,X) upper_bound(all(A),X)

using namespace std;

using ll=long long int;
using pi=pair<int,int>;
using qi=queue<int>;
using qp=queue<pi>;
using si=set<int>;

using vi=vector<int>;
using vll=vector<ll>;
using vs=vector<string>;
using vc=vector<char>;
using vb=vector<bool>;

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

struct pnt {
  ll x;
  ll y;
};

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N,D;
  cin >> N >> D;
  map<int,int> A;
  set<pair<int,int>,greater<pair<int,int>>> Scores;

  for (int i = 0; i < N; i++){
    int x;
    cin >> x;
    A[x]++;
  }

  for(auto x: A){
    int score = 0;
    if(x.first >= D){
      score += A[x.first - D];
    }
    if(A.count(D+x.first)){
      score += A[D+x.first];
    }
    Scores.insert(mp(score,x.first));
  }

  map<int,int> Decrease;
  int res = 0;
  while(!Scores.empty()){
    // cout<<res<<endl;
    auto x = *Scores.begin();
    Scores.erase(x);

    if(x.first - Decrease[x.second] == 0){
      continue;
    }
    res += A[x.second];
    Decrease[D+x.second] += A[x.second];
    Decrease[x.second - D] += A[x.second];
  }

  cout << res << endl;

  return 0;
}
