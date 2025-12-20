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
  int N,M;
  cin >> N >> M;
  vi Cost(N);
  vvi zoo(N);
  for(int i=0;i<N;i++)cin>>Cost[i];
  for(int i=0;i<M;i++){
    int k;cin>>k;
    for(int j=0;j<k;j++){
      int a;
      cin>>a;
      a--;
      zoo[a].eb(i);
    }
  }

  vi P(N);
  for(int i=0;i<N;i++)P[i]=i;

  ll res=LONG_MAX;
  // do{
  //   ll score=0;
  //   vi seen(M,0);
  //   set<int> S;
  //   for(int i=0;i<M;i++){
  //     S.insert(i);
  //   }
  //   for(auto p: P){
  //     for(auto z: zoo[p]){
  //       seen[z]++;
  //       if(seen[z] == 2){
  //         S.erase(z);
  //       }
  //     }
  //     score+=Cost[p];
  //     if(S.size() == 0)break;
  //   }
  //   chmin(res,score);
  // } while (next_permutation(all(P)));

  for(int i=0;i<1<<N;i++){
    ll score=0;
    vi seen(M,0);
    set<int> S;
    for(int j=0;j<M;j++){
      S.insert(j);
    }
    vi p;
    for(int j=0;j<N;j++){
      if(i>>j&1){
        p.eb(j);
        score+=Cost[j];
        for(auto z: zoo[j]){
          seen[z]++;
          if(seen[z] == 2){
            S.erase(z);
          }
        }
      }
      if(S.size() == 0)break;
    }
    if(S.size() == 0){
      chmin(res,score);
      continue;
    }else{
      for(int j=0;j<1<<p.size();j++){
        ll score2=score;
        vi seen2=seen;
        set<int> S2=S;
        for(int k=0;k<p.size();k++){
          if(j>>k&1){
            score2+=Cost[p[k]];
            for(auto z: zoo[p[k]]){
              seen2[z]++;
              if(seen2[z] == 2){
                S2.erase(z);
              }
            }
          }
          if(S2.size() == 0)break;
        }
        if(S2.size() == 0){
          chmin(res,score2);
          continue;
        }
      }
    }
  }
  cout<<res<<endl;
  return 0;
}