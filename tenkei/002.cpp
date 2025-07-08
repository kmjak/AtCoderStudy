#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define g(i,t) get<i>(t)

#define tos(n) to_string(n)
#define toc(n) '0' + n
#define toi(s) stoi(s)
#define btoi(b) static_cast<int>(b.to_ulong())

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
  int N;
  cin>>N;
  set<string> res;
  for(int i=0;i<1<<N;i++){
    string s;
    for(int j=0;j<N;j++){
      if(i & (1<<j)){
        s += '(';
      }else{
        s += ')';
      }
    }
    stack<char> st;
    bool ok = true;
    for(auto c : s){
      if(c == '('){
        st.push(c);
      }else{
        if(st.empty()){
          ok = false;
          break;
        }
        st.pop();
      }
    }
    if(ok&&st.empty()) res.insert(s);
  }
  for(auto s : res){
    cout << s << endl;
  }
  return 0;
}