template <long N>
struct Tarjan {
    vector<long> outs[N];

    void add(long from, long to) {
        outs[from].push_back(to);
    }

    long id_self[N];
    long id_low[N];
    long route[N];

    void dfs(long (&scc)[N], long from, long &last, long &now, long &now_scc) {
        id_self[from] = now;
        id_low[from] = now;
        now += 1;

        route[from] = last;
        last = from;

        for (long j = 0; j < outs[from].size(); ++j) {
            long to = outs[from][j];

            if (!id_self[to]) {
                dfs(scc, to, last, now, now_scc);

                id_low[from] = min(id_low[from], id_low[to]);
            } else if (!scc[to]) {
                id_low[from] = min(id_low[from], id_self[to]);
            }
        }

        if (id_low[from] == id_self[from]) {
            while (last != from) {
                scc[last] = now_scc;
                last = route[last];
            }

            scc[last] = now_scc;
            last = route[last];
            now_scc += 1;
        }
    }
}