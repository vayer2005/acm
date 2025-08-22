signed main() {
    cin >> n >> q;
 
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    map<int, pair<int,int>> hash_val;
    for (int i = 1; i <= n; i++) {
        if (hash_val.find(a[i]) == hash_val.end()) {
            hash_val[a[i]].first = rand() % (1LL << 62);
            hash_val[a[i]].second = rand() % (1LL << 62);
        }
    }
}