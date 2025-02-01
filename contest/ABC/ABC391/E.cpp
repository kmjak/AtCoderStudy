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

struct pnt {
  ll x;
  ll y;
};

char f(string t)
{
  int c=0;
  if(t[0]=='0') c++;
  if(t[1]=='0') c++;
  if(t[2]=='0') c++;
  if(c>1){
    return '0';
  }else{
    return '1';
  }
}

vector<vector<pair<string,bool>>> Str(13);

int dfs(int k,int p,int c,char prev)
{
  if(k==-1){
    return 0;
  }
  rep(i,0,Str[k].size()){
    rep(j,p,3){
      if(Str[k][i].first[j]==prev){
        if(prev=='0'){
          cout<<'1';
        }else{
          cout<<'0';
        }
      }else{
        cout<<Str[k][i].first[j];
      }
    }
    cout << endl;
  }
  cout << endl;
  dfs(k-1,p,c,prev);
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  string S;
  cin >> N >> S;
  string T=S;
  int j=0;
  while(S.size()>1){
    string n="";
    N--;
    rep(i,0,pow(3,N)){
      string t=S.substr(i*3,3);
      char res=f(t);
      n+=res;
      if(res=='0'){
        Str[j].eb(t,false);
      }else{
        Str[j].eb(t,true);
      }
    }
    S=n;
    j++;
  }
  char prev=S[0];
  dfs(j-1,0,0,prev);
  return 0;
}