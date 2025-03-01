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


// 座標を表す型
struct PNT {
  ll x;
  ll y;
  bool operator<(const PNT &other) const {
    return tie(x, y) < tie(other.x, other.y);
  }
  friend ostream& operator <<(std::ostream& os, const PNT& p)
  {
    return os << ' ' << p.y << " " << p.x;
  }

  bool operator==(const PNT &other) const {
    return x == other.x && y == other.y;
  }
};

struct LINK {
  set<ll> idx;
  ll money;
};

// 線路の置いてある座標と方向を表す型
// line=線路の座標
// direction=線路の方向
struct LINE {
  PNT line;
  int direction;

  bool operator==(const LINE &other) const {
    return line == other.line && direction == other.direction;
  }
  friend ostream& operator <<(std::ostream& os, const LINE& l)
  {
    return os << l.line << " " << l.direction;
  }
};

// 駅の収益と開業時期を表す型
struct STATION{
  ll profit;
  int openAt;
};

struct RANKING{
  PNT fromStation;
  PNT toStation;
  set<ll> idx;
  ll maxProfit;

  bool operator<(const RANKING &other) const {
    return maxProfit < other.maxProfit;
  }
};

// N,M,K,Tの型定義
ll N,M,K;
int T;
int turn=0;

// 駅の座標から通える家または職場の座標を計算する時に使う
vi dx={0,0,0,0,0,2,1,-1,-2,1,1,-1,-1};
vi dy={0,2,1,-1,-2,0,0,0,0,1,-1,1,-1};

// 上下左右の移動
vi dx4={0,1,0,-1};
vi dy4={1,0,-1,0};

// House,Jobの座標を格納するvector
vector<PNT> House(1610);
vector<PNT> Job(1610);

// 駅の情報を格納するvector
vector<STATION> stations;

// 50*50のグリッド
// -1:何もない
// -2:駅
// -3:駅の周辺
// -4:線路
vvi G(50,vi(50,-1));

vector<vector<map<PNT,LINK>>> GridStations(50,vector<map<PNT,LINK>>(50));

priority_queue<pair<ll,RANKING>> scoreRanking;

// 駅と駅の距離を求める(今回は金額を求めるのに使う)
ll calcMoney(PNT from, PNT to)
{
  return abs(from.x-to.x)+abs(from.y-to.y);
}

// 座標が範囲内かどうか
bool isRange(PNT p)
{
  return 0<=p.x && p.x<50 && 0<=p.y && p.y<50;
}

void markPossiblePlace(PNT house, PNT job,int idx)
{
  ll profit=calcMoney(house,job);
  rep(i,0,13){
    PNT houseStation=PNT{house.x+dx[i],house.y+dy[i]};
    rep(j,0,13){
      PNT jobStation=PNT{job.x+dx[j],job.y+dy[j]};
      if(isRange(houseStation) && isRange(jobStation)){
        GridStations[houseStation.y][houseStation.x][jobStation].idx.insert(idx);
        GridStations[houseStation.y][houseStation.x][jobStation].money+=profit;
        GridStations[jobStation.y][jobStation.x][houseStation].idx.insert(idx);
        GridStations[jobStation.y][jobStation.x][houseStation].money+=profit;
      }
    }
  }
}

void removeStation(PNT job, PNT house,int idx)
{
  ll profit=calcMoney(house,job);
  rep(i,0,13){
    PNT houseStation=PNT{house.x+dx[i],house.y+dy[i]};
    rep(j,0,13){
      PNT jobStation=PNT{job.x+dx[j],job.y+dy[j]};
      if(isRange(houseStation) && isRange(jobStation)){
        GridStations[houseStation.y][houseStation.x][jobStation].idx.erase(idx);
        GridStations[houseStation.y][houseStation.x][jobStation].money-=profit;
        GridStations[jobStation.y][jobStation.x][houseStation].idx.erase(idx);
        GridStations[jobStation.y][jobStation.x][houseStation].money-=profit;
      }
    }
  }
}

vector<LINE> bfs(PNT start, PNT goal)
{
  // 各座標までの距離を記録する
  vvi dist=G;
  queue<PNT> q;
  q.push(start);
  // スタート地点を決める
  dist[start.y][start.x]=0;

  bool isGoal=false;

  // bfsで経路を探す
  while(!q.empty()){
    PNT now=q.front();
    q.pop();
    if(now.x==goal.x && now.y==goal.y){
      isGoal=true;
      break;
    }
    rep(i,0,4){
      PNT next={now.x+dx4[i],now.y+dy4[i]};
      if(isRange(next) && dist[next.y][next.x]==-1){
        dist[next.y][next.x]=dist[now.y][now.x]+1;
        q.push(next);
      }
    }
  }

  // ゴール地点に行けない場合終了
  if(!isGoal){
    return vector<LINE>{};
  }

  // 経路を記録する

  PNT now=goal;
  int distance=dist[now.y][now.x];

  if(distance<5){
    return vector<LINE>{};
  }

  // 返す経路を保持
  vector<LINE> result(distance-1,LINE{});

  rrep(i,distance,-1){
    rep(j,0,4){
      PNT next={now.x+dx4[j],now.y+dy4[j]};
      if(isRange(next)){
        if(dist[next.y][next.x]!=i-1) continue;
        now=next;
        if(now.x==start.x && now.y==start.y) break;
        result[distance-i]=LINE{now,(j+1)%2+1};

        // 進行方向が変わる場合はその方向を記録する
        if(i!=distance){
          if(result[distance-i].direction!=result[distance-i-1].direction){
            LINE &prev=result[distance-i-1];
            LINE &current=result[distance-i];
            if(distance-i-2<0){
              if(current.direction==1){
                if(prev.line.x+1==current.line.x){
                  if(prev.line.y+1==start.y) prev.direction=6;
                  else prev.direction=5;
                }else{
                  if(prev.line.y+1==start.y) prev.direction=3;
                  else prev.direction=4;
                }
              }else{
                if(prev.line.y+1==current.line.y){
                  if(prev.line.x+1==start.x) prev.direction=6;
                  else prev.direction=3;
                }
                else{
                  if(prev.line.x+1==start.x) prev.direction=5;
                  else prev.direction=4;
                }
              }
            }else{
              LINE &prev2=result[distance-i-2];
              if(current.direction==1){
                if(prev.line.x+1==current.line.x){
                  if(prev.line.y+1==prev2.line.y) prev.direction=6;
                  else prev.direction=5;
                }else{
                  if(prev.line.y+1==prev2.line.y) prev.direction=3;
                  else prev.direction=4;
                }
              }else{
                if(prev.line.y+1==current.line.y){
                  if(prev.line.x+1==prev2.line.x) prev.direction=6;
                  else prev.direction=3;
                }else{
                  if(prev.line.x+1==prev2.line.x) prev.direction=5;
                  else prev.direction=4;
                }
              }
            }
          }
        }
        break;
      }
    }
  }
  LINE &current=result[distance-2];
  LINE prev=result[distance-3];
  if(current.direction!=prev.direction){
    if(current.direction==1){
      if(current.line.x+1==goal.x){
        if(current.line.y+1==goal.y) current.direction=6;
        else current.direction=5;
      }else{
        if(current.line.y+1==goal.y) current.direction=3;
        else current.direction=4;
      }
    }else{
      if(current.line.y+1==goal.y){
        if(current.line.x+1==goal.x) current.direction=6;
        else current.direction=3;
      }else{
        if(current.line.x+1==goal.x) current.direction=5;
        else result[distance-1].direction=4;
      }
    }
  }
  return result;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // N,M,K,Tを入力
  cin>>N>>M>>K>>T;
  rep(i,0,M){
    cin>>House[i].y>>House[i].x>>Job[i].y>>Job[i].x;
    markPossiblePlace(House[i],Job[i],i);
  }

  // どの駅からどの駅まで線路を引くか
  bool isDecide=false;

  // 駅の収入の高い順に並べる
  rep(i,0,50){
    rep(j,0,50){
      PNT from = PNT{j,i};
      repa(to,GridStations[i][j]){
        // res=bfs(from,to.first);
        // int turn=res.size();
        ll d = calcMoney(from,to.first);
        if(d*100+10000>K)continue;
        scoreRanking.push(mp(to.second.money, RANKING{from, to.first, to.second.idx, to.second.money}));
      }
    }
  }

  while(!isDecide&&!scoreRanking.empty()){
    pair<ll,RANKING> select=scoreRanking.top();
    scoreRanking.pop();
    if(select.first==-1||select.second.idx.size()==0){
      break;
    }
    PNT fromStation=select.second.fromStation;
    PNT toStation=select.second.toStation;
    set<ll> idx=select.second.idx;
    ll profit=select.first;

    vector<LINE> res=bfs(fromStation,toStation);
    if(res==vector<LINE>{}){
      continue;
    }
    ll resSize=res.size();
    if(resSize!=0){
      if(K>=100*resSize+10000&&(T-turn)*profit>=100*resSize+10000){
        cout<<0<<fromStation<<endl;
        cout<<0<<toStation<<endl;
        repa(l,res){
          cout<<l.direction<<l.line<<endl;
        }
        turn+=resSize+2;
        K-=(100*resSize+10000);
        isDecide=true;
      }
    }
  }
  rep(i,turn,T/2){
    cout<<-1<<endl;
  }
  turn=T/2;
  rep(i,turn,T){
    cout<<-1<<endl;
  }
}