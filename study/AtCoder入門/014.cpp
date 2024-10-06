#include <bits/stdc++.h>

#define rep(i,s,n) for(auto i = s; i < n; i++)
#define rrep(i,s,n) for(auto i = s; i >= n; i--)
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
  // string s;
  // cin >> s;
  // int c = 0;
  // int start;
  // map<string,int> words;
  // string word = "";
  // rep(i,0,s.size()){
  //   word += tolower(s[i]);
  //   if(i == 0) {
  //     continue;
  //   }
  //   if(isupper(s[i])){
  //     c++;
  //     i++;
  //     if(auto it = words.find(word); it != end(words)){
  //       words[word]++;
  //     }else{
  //       words.insert(mp(word,1));
  //     }
  //     word = tolower(s[i]);
  //   }
  // }
  // repa(x,words){
  //   string w = x.first;
  //   w[0] = (char(toupper(w[0])));
  //   w[w.size()-1] = (char(toupper(w[w.size()-1])));
  //   rep(i,0,x.second){
  //     cout << w;
  //   }
  // }
  // cout << endl;

  string s;
  cin >> s;
  vs words;

  rep(i,0,s.size()){
    int j = i + 1;
    while(j < s.size() && islower(s[j])) j++;
    string word = s.substr(i,j-i+1);
    word[0] = tolower(word[0]);
    word.back() = tolower(word.back());
    words.pb(word);
    i = j;
  }

  sort(all(words));

  repa(x,words){
    x[0] = toupper(x[0]);
    x.back() = toupper(x.back());
    cout << x;
  }
  cout << endl;
  return 0;
}