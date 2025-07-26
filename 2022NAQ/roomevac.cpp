#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 400000;

struct Dinic {
  struct edg{ int pos, cap, rev; };
  vector<edg> gph[MAXN];
  int dis[MAXN];
  int pnt[MAXN];
  int que[MAXN];
  short did[MAXN];
  short pid[MAXN];
  int cid;
  Dinic(int n) {
    cid = 0;
  }
  void add_edge(int s, int e, int x){
      gph[s].push_back({e, x, (int)gph[e].size()});
      gph[e].push_back({s, 0, (int)gph[s].size()-1});
  }
  bool bfs(int src, int sink){
    cid++;
    int qsz = 0;
    que[qsz++] = src;
    dis[src] = 1; did[src] = cid;
    int idx = 0;
    while(idx < qsz && did[sink] != cid){
      int x = que[idx++];
      for(auto &e : gph[x]){
        if(e.cap > 0 && did[e.pos] != cid){
          did[e.pos] = cid;
          dis[e.pos] = dis[x] + 1;
          que[qsz++] = e.pos;
        }
      }
    }
    return did[sink] == cid;
  }
  int dfs(int x, int sink, int f){
    if(x == sink) return f;
    if(pid[x] != cid) {
      pid[x] = cid;
      pnt[x] = 0;
    }
    for(; pnt[x] < gph[x].size(); pnt[x]++){
      edg e = gph[x][pnt[x]];
      if(e.cap > 0 && did[e.pos] == cid && dis[e.pos] == dis[x] + 1){
        int w = dfs(e.pos, sink, min(f, e.cap));
        if(w){
          gph[x][pnt[x]].cap -= w;
          gph[e.pos][e.rev].cap += w;
          return w;
        }
      }
    }
    return 0;
  }
  int64_t flow(int src, int sink){
      int64_t ret = 0;
      while(bfs(src, sink)){
          int r;
          while((r = dfs(src, sink, 2e9))) ret += r;
      }
      return ret;
  }
};


Dinic* dinic;

int main() {
  int r, c, maxt;
  cin >> r >> c >> maxt;
  {
    string s;
    getline(cin, s);
  }
  maxt++;
  vector<string> g(r);
  for(int i = 0; i < r; i++) getline(cin, g[i]);
  dinic = new Dinic(r*c*maxt*2 + 2);
  int src = r*c*maxt*2;
  int snk = src + 1;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(g[i][j] == 'P') {
        dinic->add_edge(src, i*c+j, 1);
      }
      else if(g[i][j] == 'E') {
        for(int x = 0; x < maxt; x++) {
          dinic->add_edge(i*c+j + r*c + x*2*r*c, snk, 1);
        }
      }
      if(g[i][j] != '#') {
        int dx[5]{-1,0,1,0,0};
        int dy[5]{0,1,0,-1,0};
        for(int x = 0; x < maxt; x++) {
          dinic->add_edge(i*c+j + 2*r*c*x, i*c+j + 2*r*c*x + r*c, 1);
          if(x+1 < maxt) {
            for(int k = 0; k < 5; k++) {
              int nx = i + dx[k];
              int ny = j + dy[k];
              if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != '#') {
                dinic->add_edge(i*c+j + 2*r*c*x + r*c, nx*c+ny + 2*r*c*(x+1), 1);
              }
            }
          }
        }
      }
    }
  }
  int nump = 0;
  for(int i = 0; i < r; i++) nump += count(g[i].begin(), g[i].end(), 'P');
  cout << dinic->flow(src, snk) << "\n";
}