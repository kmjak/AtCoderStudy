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

int N,Q;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>N>>Q;
  vector<ll> box_to_label(N),label_to_box(N),pigeon_to_box(N);
  iota(begin(box_to_label), end(box_to_label), 0LL);
  iota(begin(label_to_box), end(label_to_box), 0LL);
  iota(begin(pigeon_to_box), end(pigeon_to_box), 0LL);
  while(Q--){
    int opt;
    cin>>opt;
    if(opt==1){
      ll pigeon,to;
      cin>>pigeon>>to;
      pigeon--;
      to--;
      pigeon_to_box[pigeon]=label_to_box[to];
    }else if(opt==2){
      ll label1,label2;
      cin>>label1>>label2;
      label1--;
      label2--;
      swap(label_to_box[label1],label_to_box[label2]);
      swap(box_to_label[label_to_box[label1]],box_to_label[label_to_box[label2]]);
    }else{
      ll pigeon;
      cin>>pigeon;
      pigeon--;
      cout<<box_to_label[pigeon_to_box[pigeon]]+1<<endl;
    }
  }
  return 0;
}