#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define int long long
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NIL -1
const int mod = 1e9+7;
const int NUM = 1e6+5; 
const int N = 2e5+5;
const double EPS = 1e-9;
const int INF = 1e9 + 13;
 
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
 
 
 
vector<int> lp, sieve;
vector<int> pr;
vi pow2(2e5+1, 0);
vector<int> power;
vector<int> fact(2e5 + 5, 0);
vector<int> inv_fact(2e5 + 5, 0);

int comp = 1;
map<int,int> toc; 

// A class that represents an directed graph
class Graph {
    int V; // No. of vertices
    list<int>* adj; // A dynamic array of adjacency lists

    // A Recursive DFS based function used by SCC()
    void SCCUtil(int u, int disc[], int low[],
                 stack<int>* st, bool stackMember[]);

public:
    Graph(int V); // Constructor
    void addEdge(int v,
                 int w); // function to add an edge to graph
    void SCC(); // prints strongly connected components
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

// A recursive function that finds and prints strongly
// connected components using DFS traversal u --> The vertex
// to be visited next disc[] --> Stores discovery times of
// visited vertices low[] -- >> earliest visited vertex (the
// vertex with minimum
//             discovery time) that can be reached from
//             subtree rooted with current vertex
// *st -- >> To store all the connected ancestors (could be
// part
//         of SCC)
// stackMember[] --> bit/index array for faster check
// whether
//                 a node is in stack
void Graph::SCCUtil(int u, int disc[], int low[],
                    stack<int>* st, bool stackMember[])
{
    // A static variable is used for simplicity, we can
    // avoid use of static variable by passing a pointer.
    static int time = 0;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    // Go through all vertices adjacent to this
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'

        // If v is not visited yet, then recur for it
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember);

            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low
            // value)
            low[u] = min(low[u], low[v]);
        }

        // Update low value of 'u' only of 'v' is still in
        // stack (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low
        // value)
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }

    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    if (low[u] == disc[u]) {
        while (st->top() != u) {
            w = (int)st->top();
            toc[w] = comp;
            stackMember[w] = false;
            st->pop();
        }
        
        w = (int)st->top();
        toc[w] = comp;
        comp++;
        stackMember[w] = false;
        st->pop();
    }
}



// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC()
{
    int* disc = new int[V];
    int* low = new int[V];
    bool* stackMember = new bool[V];
    stack<int>* st = new stack<int>();

    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }

    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            SCCUtil(i, disc, low, st, stackMember);
}

map<int,int> outdeg;
map<int, vi> child;

int dfs(int v) {
    int ret = 1;

    for (int x : child[v]) {
        ret = (ret * dfs(x)) % mod;
    }
    ret = (ret + 1) % mod;
    return ret;
}


void solve() {
    int n;
    cin >> n;

    
    Graph g1(n);
    int ed;
    vvi edges;
    for (int i = 0; i < n; i++) {
        cin >> ed;
        ed--;
        g1.addEdge(i, ed);
        edges.pb({i,ed});
    }

    g1.SCC();
    for (auto &x : edges) {
        int c1 = toc[x[0]];
        int c2 = toc[x[1]];
        if (c1 == c2) continue;
        child[c2].pb(c1);
        outdeg[c1]++;
    }

    int fin = 1;
    for (int i = 1; i < comp; i++) {

        int appear = outdeg[i];
        if (appear == 0) {
            int d = dfs(i);
            fin = (fin * d) % mod;
        }
    }

    fin = (fin - 1 + mod) % mod;
    cout << fin << endl;



   
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}