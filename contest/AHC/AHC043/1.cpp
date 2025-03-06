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
  bool operator<(const pnt &other) const {
    return tie(x, y) < tie(other.x, other.y);
  }
  friend ostream& operator <<(std::ostream& os, const pnt& p)
  {
    return os << ' ' << p.y << " " << p.x;
  }
};

struct line {
  pnt l;
  int direction;
};

int N,M,K,T;

vector<pnt> House(1610);
vector<pnt> Job(1610);

vector<vector<map<pnt,int>>> G_House(50,vector<map<pnt,int>>(50)),G_Job(50,vector<map<pnt,int>>(50));
vi dx={0,0,0,0,0,2,1,-1,-2,1,1,-1,-1};
vi dy={0,2,1,-1,-2,0,0,0,0,1,-1,1,-1};
vi dx4={0,1,0,-1};
vi dy4={1,0,-1,0};

vvi G(50,vi(50));

bool isRange(pnt p){
  return 0<=p.x && p.x<50 && 0<=p.y && p.y<50;
}

void markPossiblePlace(pnt house,pnt job)
{
  set<pnt> visited_H,visited_J;
  rep(i,0,13){
    rep(j,0,13){
      pnt fromNextHouse={house.x+dx[i],house.y+dy[i]};
      pnt toNextJob={job.x+dx[j],job.y+dy[j]};
      if(isRange(fromNextHouse) && isRange(toNextJob)){
        G_Job[toNextJob.y][toNextJob.x][fromNextHouse]++;
      }
      pnt fromNextJob={job.x+dx[i],job.y+dy[i]};
      pnt toNextHouse={house.x+dx[j],house.y+dy[j]};
      if(isRange(fromNextJob) && isRange(toNextHouse)){
        G_House[toNextHouse.y][toNextHouse.x][fromNextJob]++;
      }
    }
  }
}

vector<line> bfs(pnt start, pnt goal)
{
  vector<line> res;
  vvi dist(50,vi(50,-1));
  queue<pnt> q;
  q.push(start);
  dist[start.y][start.x]=0;
  while(!q.empty()){
    pnt now=q.front();
    q.pop();
    if(now.x==goal.x && now.y==goal.y){
      break;
    }
    rep(i,0,4){
      pnt next={now.y+dy4[i],now.x+dx4[i]};
      if(isRange(next) && dist[next.y][next.x]==-1){
        dist[next.y][next.x]=dist[now.y][now.x]+1;
        q.push(next);
      }
    }
  }
  pnt now=goal;
  int t=dist[now.y][now.x];
  if(t==-1){
    return res;
  }
  res.resize(t-1);
  pnt prev={-1,-1};
  cout<<start<<goal<<endl;
  rep(i,0,50){
    rep(j,0,50){
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
  rrep(i,t,0){
    rep(j,0,4){
      pnt next={now.y+dy4[j],now.x+dx4[j]};
      if(isRange(next) && dist[next.y][next.x]==i-1){
        now=next;
        if(now.x==start.x && now.y==start.y){
          break;
        }
        res[t-i]=line{now,j%2+1};
        if(i==t){
          break;
        }
        if(res[t-i].direction!=res[t-i-1].direction){
          if(prev.x+1==now.x&&prev.y+1==res[t-i-2].l.y)res[t-i-1].direction=6;
          if(prev.x-1==now.x&&prev.y-1==res[t-i-2].l.y)res[t-i-1].direction=4;
          if(prev.x+1==now.x&&prev.y-1==res[t-i-2].l.y)res[t-i-1].direction=3;
          if(prev.x-1==now.x&&prev.y+1==res[t-i-2].l.y)res[t-i-1].direction=5;
        }
        break;
      }
    }
    prev=now;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M >> K >> T;
  rep(i,0,M){
    cin>>House[i].x>>House[i].y>>Job[i].x>>Job[i].y;
    markPossiblePlace(House[i],Job[i]);
  }

  int fromMaxHouse=-1;
  int fromMaxJob=-1;
  pnt fromMaxHouseIdx={-1,-1},toMaxJobIdx={-1,-1};
  pnt fromMaxJobIdx={-1,-1},toMaxHouseIdx={-1,-1};
  rep(i,0,50){
    rep(j,0,50){
      int MaxHouse=max_element(all(G_House[i][j]),[](auto a,auto b){return a.second<b.second;})->second;
      if(MaxHouse>fromMaxHouse){
        fromMaxHouse=MaxHouse;
        fromMaxHouseIdx={i,j};
        toMaxJobIdx=max_element(all(G_House[i][j]),[](auto a,auto b){return a.second<b.second;})->first;
      }
      int MaxJob=max_element(all(G_Job[i][j]),[](auto a,auto b){return a.second<b.second;})->second;
      if(MaxJob>fromMaxJob){
        fromMaxJob=MaxJob;
        fromMaxJobIdx={i,j};
        toMaxHouseIdx=max_element(all(G_Job[i][j]),[](auto a,auto b){return a.second<b.second;})->first;
      }
    }
  }
  vector<line> res=bfs(fromMaxHouseIdx,toMaxJobIdx);
  K-=10000;
  if(K<100*res.size()){
    rep(i,0,T){
      cout<<-1<<endl;
      return 0;
    }
  }
  if(fromMaxHouse>fromMaxJob){
    cout<<0<<fromMaxHouseIdx<<endl;
    cout<<0<<toMaxJobIdx<<endl;
  }else{
    cout<<0<<toMaxHouseIdx<<endl;
    cout<<0<<fromMaxJobIdx<<endl;
  }
  rep(i,0,res.size()){
    cout<<res[i].direction<<res[i].l<<endl;
  }
  rep(i,0,T-res.size()-2){
    cout<<-1<<endl;
  }
  return 0;
}