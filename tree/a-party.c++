#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
unordered_map<int, vector<int>> umap;

int dfs(int node) {
    if (umap.find(node) == umap.end()) {
        return 1;
    } else {
        vector<int> children = umap[node];
        int v = 0;
        for (int child : children) {
            v = max(v, dfs(child));
        }
        return 1 + v;
    }
}

int main() {
    int n;
    cin >> n;
    int parent;   

    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (umap.find(parent) == umap.end()) {
            vector<int> child = {i+1};
            umap[parent] = child;
        } else {
            vector<int> c = umap[parent];
            c.push_back(i+1);
            umap[parent] = c;
        }
    }

    int r = dfs(-1)-1;
    cout << r << endl;

}