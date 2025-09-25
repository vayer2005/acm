int n,q,a[N];
multiset<int> seg[4*N+5];
void build(int node,int l,int r){
    if (l==r){
        seg[node].insert(a[l]);
        return;
    }int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    for (int i=l;i<=r;i++) seg[node].insert(a[i]);
    return;
}
void edit(int node,int l,int r,int idx,int val){
    if (l==r){
        seg[node].erase(a[idx]);
        seg[node].insert(val);
        return;
    }int mid=(l+r)/2;
    if (idx<=mid) edit(node*2,l,mid,idx,val);
    else edit(node*2+1,mid+1,r,idx,val);
    seg[node].erase(a[idx]);
    seg[node].insert(val);
    return;
}
int query(int node, int l, int r, int lx, int rx, int x) {
    if (l > rx || r < lx) return 0;  
    if (l >= lx && r <= rx) {      
        auto it = seg[node].upper_bound(x);
        return distance(it, seg[node].end()); 
    }
    int mid = (l + r) / 2;
    return query(node*2, l, mid, lx, rx, x) +
           query(node*2+1, mid+1, r, lx, rx, x);
}

int queryLess(int node, int l, int r, int lx, int rx, int x) {
    if (l > rx || r < lx) return 0;  // no overlap
    if (l >= lx && r <= rx) {        // total overlap
        auto it = seg[node].lower_bound(x);
        return distance(seg[node].begin(), it); // count elements < x
    }
    int mid = (l + r) / 2;
    return queryLess(node*2, l, mid, lx, rx, x) +
           queryLess(node*2+1, mid+1, r, lx, rx, x);
}
