// AI使わずに初AC!!!!!!!!

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


// 頭がこんがらがったのでコメントアウトで何をしているか整理して書いてみる

// 座標を表す構造体
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

// 線路の置いてある座標と方向を表す構造体
// line=線路の座標
// direction=線路の方向
struct line {
  pnt line;
  int direction;
};

// N,M,K,Tの型定義
int N,M,K,T;

// House,Jobの座標を格納するvector
vector<pnt> House(1610);
vector<pnt> Job(1610);

// 駅の座標から通える家または職場の座標を計算する時に使う
vi dx={0,0,0,0,0,2,1,-1,-2,1,1,-1,-1};
vi dy={0,2,1,-1,-2,0,0,0,0,1,-1,1,-1};
// 上下左右の移動
vi dx4={0,1,0,-1};
vi dy4={1,0,-1,0};

// どこの家からどこの駅に行けるか、どこの職場からどこの駅に行けるかを記録する
vector<vector<map<pnt,vector<pnt>>>> GHouseStation(50,vector<map<pnt,vector<pnt>>>(50)),GJobStation(50,vector<map<pnt,vector<pnt>>>(50));

// GHouseCnt:家の座標をキーとして家の数を記録するのでGJobStationに使う
// GJobCnt:職場の座標をキーとして職場の数を記録するのでGHouseStationに使う
map<pnt,int> GHouseCnt,GJobCnt;

// 50*50のグリッド
// -1:何もない
// 0:駅
// 1:線路
vvi G(50,vi(50));

// 座標が範囲内かどうか
bool isRange(pnt p)
{
  return 0<=p.x && p.x<50 && 0<=p.y && p.y<50;
}

// t回-1を出力する
void wait(int t)
{
  rep(i,0,t){
    cout<<-1<<endl;
  }
}

// houseとjobを結ぶ駅の候補を探す
void markPossiblePlace(pnt house, pnt job)
{
  // fromのstationからtoのstationへの経路を記録する
  map<pnt,vector<pnt>> visitedHouseStation,visitedJobStation;
  rep(i,0,13){
    rep(j,0,13){
      pnt fromHouse={house.x+dx[i],house.y+dy[i]};
      pnt toJob={job.x+dx[j],job.y+dy[j]};
      if(isRange(fromHouse) && isRange(toJob)){
        visitedJobStation[toJob].eb(fromHouse);
      }
      pnt fromJob={job.x+dx[i],job.y+dy[i]};
      pnt toHouse={house.x+dx[j],house.y+dy[j]};
      if(isRange(fromJob) && isRange(toHouse)){
        visitedHouseStation[toHouse].eb(fromJob);
      }
    }
  }
  // fromのstationからtoのstationへの経路をGHouseStationとGJobStationに記録する
  repa(toJob,visitedJobStation){
    repa(fromHouse,toJob.second){
      GJobStation[toJob.first.y][toJob.first.x][house].eb(fromHouse);
    }
  }
  repa(toHouse,visitedHouseStation){
    repa(fromJob,toHouse.second){
      GHouseStation[toHouse.first.y][toHouse.first.x][job].eb(fromJob);
    }
  }
}

vector<line> bfs(pnt start, pnt goal)
{
  // 経路を記録するvector
  vector<line> res;
  // 各座標までの距離を記録する
  vvi dist(50,vi(50,-1));
  queue<pnt> q;
  q.push(start);
  // スタート地点の距離は0
  dist[start.y][start.x]=0;

  // bfsで経路を探す
  while(!q.empty()){
    pnt now=q.front();
    q.pop();
    if(now.x==goal.x && now.y==goal.y){
      break;
    }
    rep(i,0,4){
      pnt next={now.x+dx4[i],now.y+dy4[i]};
      if(isRange(next) && dist[next.y][next.x]==-1){
        dist[next.y][next.x]=dist[now.y][now.x]+1;
        q.push(next);
      }
    }
  }

  // 経路を記録する
  pnt now=goal;
  int distance=dist[now.y][now.x];

  // ゴール地点に行けない場合は空のvectorを返す
  if(distance==-1){
    return res;
  }
  res.resize(distance-1);
  rrep(i,distance,-1){
    rep(j,0,4){
      pnt next={now.x+dx4[j],now.y+dy4[j]};
      if(isRange(next) && dist[next.y][next.x]==i-1){
        now=next;
        if(now.x==start.x && now.y==start.y){
          break;
        }
        res[distance-i]=line{now,(j+1)%2+1};
        // 進行方向が変わる場合はその方向を記録する
        if(i!=distance){
          if(res[distance-i].direction!=res[distance-i-1].direction){
            line &prev=res[distance-i-1];
            if(distance-i-2<0){
              if(prev.direction==1){
                if(prev.line.y<now.y&&goal.x<prev.line.x) prev.direction=3;
                if(prev.line.y<now.y&&goal.x>prev.line.x) prev.direction=6;
                if(prev.line.y>now.y&&goal.x>prev.line.x) prev.direction=4;
                if(prev.line.y>now.y&&goal.x<prev.line.x) prev.direction=5;
              }else{
                if(prev.line.x<now.x&&goal.y<prev.line.y) prev.direction=5;
                if(prev.line.x<now.x&&goal.y>prev.line.y) prev.direction=6;
                if(prev.line.x>now.x&&goal.y>prev.line.y) prev.direction=3;
                if(prev.line.x>now.x&&goal.y<prev.line.y) prev.direction=4;
              }
              continue;
            }
            if(prev.direction==1){
              if(prev.line.y<now.y&&res[distance-i-2].line.x<prev.line.x) prev.direction=3;
              if(prev.line.y<now.y&&res[distance-i-2].line.x>prev.line.x) prev.direction=6;
              if(prev.line.y>now.y&&res[distance-i-2].line.x>prev.line.x) prev.direction=4;
              if(prev.line.y>now.y&&res[distance-i-2].line.x<prev.line.x) prev.direction=5;
            }else{
              if(prev.line.x<now.x&&res[distance-i-2].line.y<prev.line.y) prev.direction=5;
              if(prev.line.x<now.x&&res[distance-i-2].line.y>prev.line.y) prev.direction=6;
              if(prev.line.x>now.x&&res[distance-i-2].line.y>prev.line.y) prev.direction=3;
              if(prev.line.x>now.x&&res[distance-i-2].line.y<prev.line.y) prev.direction=4;
            }
          }
        }
        break;
      }
    }
  }
  if(res.back().direction!=res[distance-1].direction){
    if(res.back().direction==1){
      if(res.back().line.y<start.y&&res[distance-1].line.x<res.back().line.x) res.back().direction=3;
      if(res.back().line.y<start.y&&res[distance-1].line.x>res.back().line.x) res.back().direction=6;
      if(res.back().line.y>start.y&&res[distance-1].line.x>res.back().line.x) res.back().direction=4;
      if(res.back().line.y>start.y&&res[distance-1].line.x<res.back().line.x) res.back().direction=5;
    }else{
      if(res.back().line.x<start.x&&res[distance-1].line.y<res.back().line.y) res.back().direction=5;
      if(res.back().line.x<start.x&&res[distance-1].line.y>res.back().line.y) res.back().direction=6;
      if(res.back().line.x>start.x&&res[distance-1].line.y>res.back().line.y) res.back().direction=3;
      if(res.back().line.x>start.x&&res[distance-1].line.y<res.back().line.y) res.back().direction=4;
    }
  }
  if(res.front().direction!=res[1].direction){
    if(res.front().direction==1){
      if(res.front().line.y<res[1].line.y&&start.x<res.front().line.x) res.front().direction=6;
      if(res.front().line.y<res[1].line.y&&start.x>res.front().line.x) res.front().direction=3;
      if(res.front().line.y>res[1].line.y&&start.x>res.front().line.x) res.front().direction=5;
      if(res.front().line.y>res[1].line.y&&start.x<res.front().line.x) res.front().direction=4;
    }else{
      if(res.front().line.x<res[1].line.x&&start.y<res.front().line.y) res.front().direction=6;
      if(res.front().line.x<res[1].line.x&&start.y>res.front().line.y) res.front().direction=5;
      if(res.front().line.x>res[1].line.x&&start.y>res.front().line.y) res.front().direction=3;
      if(res.front().line.x>res[1].line.x&&start.y<res.front().line.y) res.front().direction=4;
    }
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // N,M,K,Tを入力
  cin >> N >> M >> K >> T;

  // House,Jobの座標を入力
  rep(i,0,M){
    cin>>House[i].y>>House[i].x>>Job[i].y>>Job[i].x;
    GHouseCnt[House[i]]++;
    GJobCnt[Job[i]]++;
    markPossiblePlace(House[i],Job[i]);
  }
  int maxFromHouse=-1;
  pnt fromHouseIdx={-1,-1},toJobIdx={-1,-1};
  rep(i,0,50){
    rep(j,0,50){
      // jobの駅から家への経路の数を数える
      map<pnt,int> howManyUsers;
      repa(job,GJobStation[i][j]){
        repa(house,job.second){
          howManyUsers[house]++;
        }
      }
      // jobの駅から家への経路の数が最大のものを探す
      int maxHouse=0;
      pnt houseStationIdx={-1,-1};
      repa(house,howManyUsers){
        if(house.second>maxHouse){
          maxHouse=house.second;
          houseStationIdx=house.first;
        }
      }
      if(maxHouse>maxFromHouse){
        maxFromHouse=maxHouse;
        fromHouseIdx=houseStationIdx;
        toJobIdx={j,i};
      }
      // cout<<maxHouse<<" ";
    }
    // cout<<endl;
  }
  // cout<<maxFromHouse<<fromHouseIdx<<toJobIdx<<endl;

  int maxFromJob=-1;
  pnt fromJobIdx={-1,-1},toHouseIdx={-1,-1};
  rep(i,0,50){
    rep(j,0,50){
      // houseの駅からjobへの経路の数を数える
      map<pnt,int> howManyUsers;
      repa(house,GHouseStation[i][j]){
        repa(job,house.second){
          howManyUsers[job]++;
        }
      }
      // houseの駅からjobへの経路の数が最大のものを探す
      int maxJob=0;
      pnt jobStationIdx={-1,-1};
      repa(job,howManyUsers){
        if(job.second>maxJob){
          maxJob=job.second;
          jobStationIdx=job.first;
        }
      }
      if(maxJob>maxFromJob){
        maxFromJob=maxJob;
        fromJobIdx=jobStationIdx;
        toHouseIdx={j,i};
      }
      // cout<<maxJob<<" ";
    }
    // cout<<endl;
  }

  // maxFromHouseとmaxFromJobを比較して、大きい方にbfsを使って経路を求める
  // ただし、maxFromHouseとmaxFromJobが同じ場合は両方にbfsを使って経路を求めKの範囲内で距離が最大のものを選ぶ
  // それでも見つからない場合は-1を出力する
  if(maxFromHouse==maxFromJob){
    vector<line> resHouse=bfs(fromHouseIdx,toJobIdx);
    vector<line> resJob=bfs(fromJobIdx,toHouseIdx);
    K-=10000;
    if(K<100*resHouse.size() && K<100*resJob.size()){
      // どちらを選択してもKが足りない場合は-1を出力する
      wait(T);
      return 0;
    }
    else if(100*resHouse.size()>100*resJob.size()&&K>=100*resHouse.size()){
      cout<<0<<fromHouseIdx<<endl;
      cout<<0<<toJobIdx<<endl;
      rep(i,0,resHouse.size()){
        cout<<resHouse[i].direction<<resHouse[i].line<<endl;
      }
      // 余った分は-1を出力する
      wait(T-resHouse.size()-2);
    }else if(100*resHouse.size()<100*resJob.size()&&K>=100*resJob.size()){
      cout<<0<<toHouseIdx<<endl;
      cout<<0<<fromJobIdx<<endl;
      rep(i,0,resJob.size()){
        cout<<resJob[i].direction<<resJob[i].line<<endl;
      }
      // 余った分は-1を出力する
      wait(T-resJob.size()-2);
    }else{
      if(resHouse.size()>resJob.size()){
        if(resHouse.size()*100<=K){
          cout<<0<<fromHouseIdx<<endl;
          cout<<0<<toJobIdx<<endl;
          rep(i,0,resHouse.size()){
            cout<<resHouse[i].direction<<resHouse[i].line<<endl;
          }
          // 余った分は-1を出力する
          wait(T-resHouse.size()-2);
        }else{
          if(resJob.size()*100<=K){
            cout<<0<<toHouseIdx<<endl;
            cout<<0<<fromJobIdx<<endl;
            rep(i,0,resJob.size()){
              cout<<resJob[i].direction<<resJob[i].line<<endl;
            }
            // 余った分は-1を出力する
            wait(T-resJob.size()-2);
          }else{
            // どちらを選択してもKが足りない場合は-1を出力する
            // 多分ここは通過することはない
            wait(T);
            return 0;
          }
        }
      }else{
        if(resJob.size()*100<=K){
          cout<<0<<toHouseIdx<<endl;
          cout<<0<<fromJobIdx<<endl;
          rep(i,0,resJob.size()){
            cout<<resJob[i].direction<<resJob[i].line<<endl;
          }
          // 余った分は-1を出力する
          wait(T-resJob.size()-2);
        }else{
          if(resHouse.size()*100<=K){
            cout<<0<<fromHouseIdx<<endl;
            cout<<0<<toJobIdx<<endl;
            rep(i,0,resHouse.size()){
              cout<<resHouse[i].direction<<resHouse[i].line<<endl;
            }
            // 余った分は-1を出力する
            wait(T-resHouse.size()-2);
          }else{
            // どちらを選択してもKが足りない場合は-1を出力する
            wait(T);
            return 0;
          }
        }
      }
    }
  }else if(maxFromHouse>maxFromJob){
    cout<<0<<fromHouseIdx<<endl;
    cout<<0<<toJobIdx<<endl;
    vector<line> res=bfs(fromHouseIdx,toJobIdx);
    if(K<100*res.size()){
      // Kが足りない場合は-1を出力する
      wait(T);
      return 0;
    }
    rep(i,0,res.size()){
      cout<<res[i].direction<<res[i].line<<endl;
    }
    // 余った分は-1を出力する
    wait(T-res.size()-2);
  }else{
    cout<<0<<toHouseIdx<<endl;
    cout<<0<<fromJobIdx<<endl;
    vector<line> res=bfs(fromJobIdx,toHouseIdx);
    if(K<100*res.size()){
      // Kが足りない場合は-1を出力する
      wait(T);
      return 0;
    }
    rep(i,0,res.size()){
      cout<<res[i].direction<<res[i].line<<endl;
    }
    // 余った分は-1を出力する
    wait(T-res.size()-2);
  }
}