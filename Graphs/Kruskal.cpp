template<int sz> struct DSU {
    int par[sz + 5];
    int size[sz + 5];
    int numComponents;
    
    DSU() {
        for (int i = 0; i < sz + 5; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    
    // Path compression
    int find(int node) {
        if (par[node] != node) 
            par[node] = find(par[node]);
        return par[node];
    }
    
    // Union by rank
    void unite(int node1, int node2) {
        node1 = find(node1);
        node2 = find(node2);
        
        if (node1 == node2) 
            return;
        
        if (size[node1] < size[node2]) 
            swap(node1, node2);
        
        size[node1] += size[node2];
        par[node2] = node1;
        
        numComponents--;
    }
};

DSU<MAXN> D;
vector<pii> order;
vector<pair<ll, pii>> edgeList;

// Returns min weight used or -1 if cannot be fully connected
ll Kruskals() {
    D.numComponents = N;
    ll ret = 0;
    sort(edgeList.begin(), edgeList.end());
    
    for (int i = 0; i < edgeList.size() && D.numComponents > 1; i++) {
        if (D.find(edgeList[i].second.first) == D.find(edgeList[i].second.second))
            continue;
            
        D.unite(edgeList[i].second.first, edgeList[i].second.second);
        ret += edgeList[i].first;
    }
    
    return (D.numComponents > 1) ? -1LL : ret;
}
