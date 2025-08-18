
/*
Source: https://github.com/TimonKnigge/Competitive-Programming/blob/master/Kattis/tourist.cpp
TO USE: 
FlowNetwork flow(sink + 1);
create node 0 as source, final node as sink
add edges from source to all nodes with capacity 1 and cost 0
add edges from all nodes in second bipartite group to sink with capacity 1 and cost 0
add_edge(source, i, 1, 0)
add_edge(i, j, 1, cost)
add_edge(j, sink, 1, 0)
call mcmf(0, final node)
flow is the maximum flow, cost is the minimum cost
Flow is the number of edges that are used, cost is the total cost of the edges that are used

*/


#include <bits/stdc++.h>
using namespace std;

#define int long long


struct FlowNetwork {
	struct edge {
		int v, rev; int cap, cost, flo;
		edge (int _v, int _cap, int _cost) : v(_v),
			cap(_cap), cost(_cost), flo(0) { }
	};
	int V;
	vector< vector<edge> > e;
	FlowNetwork(int V) : V(V) {
		e.assign(V, vector<edge>());
	}
	void add_edge(int u, int v, int uv_cap, int uv_cost) {
		e[u].push_back(edge(v, uv_cap,  uv_cost));
		e[v].push_back(edge(u,      0, -uv_cost));
		e[u].back().rev = e[v].size() - 1;
		e[v].back().rev = e[u].size() - 1;
	}
	pair<int, int> mcmf(int s, int t);
};

vector<int> d;

typedef pair<int, int> li;
pair<int, int> FlowNetwork::mcmf(int s, int t) {
	int flow = 0, cost = 0;
	vector<pair<int, int> > p(V, {-1, -1});
	vector<int> pot(V, 0);
	d.assign(V, 9e18);
	d[s] = 0;
	
	// Set potentials
	bool ch = true;
	for (int it = 0; it < V - 1 && ch; ++it) {
		ch = false;
		for (int u = 0; u < V; ++u) {
			if (d[u] == 9e18) continue;
			for (int i = 0; i < (int)e[u].size(); ++i) {
				edge &uv = e[u][i];
				if (uv.cap == uv.flo) continue;
				int v = uv.v;
				if (d[v] == 9e18 || d[v] > d[u] + uv.cost) {
					d[v] = d[u] + uv.cost;
					ch = true;
				}
			}
		}
	}
	for (int i = 0; i < V; ++i)
		if (d[i] != 9e18) pot[i] = d[i];
	
	
	while (true) {
		d.assign(V, -1);
		d[s] = 0;
		auto comp_func = [&](int i, int j) {
			return (d[i] != d[j] ? d[i] < d[j] : i < j);
		};
		set<int, decltype(comp_func)> st(comp_func);
		st.insert(s);
		while (!st.empty()) {
			int u = *st.begin();
			st.erase(st.begin());
			for (int i = 0; i < (int)e[u].size(); ++i) {
				edge &uv = e[u][i];
				if (uv.cap == uv.flo) continue;
				int v = uv.v;
				int w = d[u] + uv.cost + pot[u] - pot[v];
				if (d[v] == -1 || w < d[v]) {
					if (st.find(v) != st.end())
						st.erase(st.find(v));
					d[v] = w;
					p[v] = {u, i};
					st.insert(v);
				}
			}
		}
		if (d[t] == -1) break;
		int u = t;
		int cap = 9e18;
		while (u != s) {
			edge &uv = e[p[u].first][p[u].second];
			cap = min(cap, uv.cap - uv.flo);
			u = p[u].first;
		}
		if (cap == 0) break;
		u = t;
		flow += cap;
		while (u != s) {
			edge &uv = e[p[u].first][p[u].second];
			edge &vu = e[uv.v][uv.rev];
			uv.flo += cap;
			vu.flo -= cap;
			cost += cap * uv.cost;
			u = p[u].first;
		}
		for (int i = 0; i < V; ++i)
			if (d[i] != -1) pot[i] += d[i];
	}
	
	return {flow, cost};
}

