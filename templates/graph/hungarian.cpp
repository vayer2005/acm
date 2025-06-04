int W[30][30]; // W is a weight graph where i is agents and j is tasks

// N is dimensions of W, 30x30 in this case.
void hungarian(int n) {
    vector<int> u(n+1), v(n+1), p(n+1), way(n+1);
    for(int i = 1; i <= n; i++) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n+1, 1<<20);
        vector<bool> used(n+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = 1<<20, j1;
            for(int j = 1; j <= n; j++) {
                if(!used[j] && W[i0][j] != (1<<20)) {
                    int cur = W[i0][j] - u[i0] - v[j];
                    if(cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if(minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for(int j = 0; j <= n; j++) {
                if(used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) {
        ans += W[p[j]][j];
    }
    printf("%d\n", ans);
}
