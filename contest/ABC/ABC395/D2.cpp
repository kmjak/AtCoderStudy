#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i > n; i--)
#define repa(i, x) for(auto i : x)
#define rrepa(i, x) for(auto i = x.rbegin(); i != x.rend(); ++i)

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

#define NO cout << "No" << endl
#define YES cout << "Yes" << endl

#define vcin(A) rep(i,0,A.size()) cin >> A[i]
#define vcout(X) rep(i, 0, X.size()) cout << X[i] << (i == X.size() - 1 ? '\n' : ' ')

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

struct swt {
  int swt1;
  int swt2;
};

struct pnt {
  int nest;
  int turn;
};

int N,Q;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>Q;
  vector<pnt> bird(N+1,{-1,-1});
  vector<swt> swt(Q);
  vi nestLastUpdated(N+1,-1);
  vi nestAt(N+1,-1);
  iota(all(nestAt),0);
  rep(i,1,N+1){
    bird[i].nest = i;
  }
  vector<pi> act;
  vi res;
  rep(i,0,Q){
    int opt;
    cin>>opt;
    if(opt==1){
      int bd,nest;
      cin>>bd>>nest;
      bird[bd].nest = nest;
      bird[bd].turn = i;
    }else if(opt==2){
      int nest1,nest2;
      cin>>nest1>>nest2;
      swt[i]= {nest1,nest2};
      nestLastUpdated[nest1] = i;
      nestLastUpdated[nest2] = i;
    }else{
      int bd;
      cin>>bd;
      int nest = bird[bd].nest;
      int turn = bird[bd].turn;
      int lastUpdated = nestLastUpdated[nest];
      rep(j,turn,lastUpdated+1){
        if(swt[j].swt1==nest){
          nest = swt[j].swt2;
          lastUpdated=nestLastUpdated[swt[j].swt2];
        }else if(swt[j].swt2==nest){
          lastUpdated=nestLastUpdated[swt[j].swt1];
          nest = swt[j].swt1;
        }
      }
      res.eb(nest);
    }
  }
  repa(x,res){
    cout<<x<<endl;
  }
  return 0;
}