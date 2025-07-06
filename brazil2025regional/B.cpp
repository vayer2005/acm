#include <bits/stdc++.h>

using namespace std;

// #define int long long int
#define pi pair<int, int>
#define pb push_back
#define fir first
#define sec second

int n, m;
int common[102][102]; 
bool has[102][1000006];
bool reach[102][102];
int par[102][102];
vector<int> adj[102];
vector<int> g[102];

// --------------------------------------------
// Helper function: returns any actor id that appears in **both** films i and j.
// If the films have no actor in common, returns -1.
// The function iterates over the smaller cast list to stay efficient.
int get_common_actor(int i, int j)
{
  if (adj[i].size() > adj[j].size())
    swap(i, j); // make sure adj[i] is the smaller list

  for (int actor : adj[i])
    if (has[j][actor])
      return actor; // first common actor found

  return -1; // no shared actor
}

// Function that prints the shortest "actor/film/.../actor" chain
// connecting actor a to actor b, or -1 if impossible.
void solve_query(int a, int b)
{
  // Iterate over every film that contains actor a
  for (int i = 0; i < n; i++)
  {
    if (!has[i][a])
      continue;

    // From film i we can reach any film j with reach[i][j] == true
    for (int j = 0; j < n; j++)
    {
      if (!reach[i][j] || !has[j][b])
        continue; // j is not reachable or does not contain actor b

      // Reconstruct one of the shortest paths i -> ... -> j
      vector<int> ans;        // alternating list: actor/film/actor/film/...
      int x = j;
      ans.pb(b);              // final actor b

      while (true)
      {
        ans.pb(x);            // film x
        if (x == i)
          break;              // reached starting film
        int nxt = par[i][x];  // predecessor film towards i
        ans.pb(common[x][nxt]); // actor linking film x and nxt
        x = nxt;              // continue backwards
      }
      ans.pb(a);              // initial actor a

      // The path was built backwards, so reverse it.
      reverse(ans.begin(), ans.end());

      // Number of films in the chain = (|ans| + 1) / 2
      cout << (ans.size() + 1) / 2 << '\n';
      for (int id : ans)
        cout << id + 1 << ' '; // convert back to 1-based ids
      cout << '\n';
      return;
    }
  }
  // No chain found
  cout << "-1\n";
}
// --------------------------------------------

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    int sz;
    cin >> sz;
    for (int j = 0; j < sz; j++)
    {
      int x;
      cin >> x;
      x--;
      has[i][x] = 1;
      adj[i].pb(x);
    }
    sort(adj[i].begin(), adj[i].end());
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int curr = get_common_actor(i, j);
      common[i][j] = curr;
      common[j][i] = curr;
      if (curr != -1)
      {
        g[i].pb(j);
        g[j].pb(i);
      }
    }
  }
  for (int ini = 0; ini < n; ini++)
  {
    reach[ini][ini] = 1;
    queue<int> q;
    q.push(ini);
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      for (int y = 0; y < n; y++)
      {
        if (!reach[ini][y] && common[x][y] != -1)
        {
          reach[ini][y] = 1;
          par[ini][y] = x;
          q.push(y);
        }
      }
    }
  }
  int q;
  cin >> q;
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    solve_query(a, b);
  }
  return 0;
}