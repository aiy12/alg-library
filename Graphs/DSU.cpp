template<int sz> struct DSU {
    int par[sz + 5];
    int size[sz + 5];
    DSU() {
        for (int i = 0; i < sz + 5; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int find(int node) { //path compression
        if (par[node] != node) par[node] = find(par[node]);
        return par[node];
    }
    void unite(int node1, int node2) { //union by rank
        node1 = find(node1);
        node2 = find(node2);
        if (node1 == node2) return;
        if (size[node1] < size[node2]) swap(node1, node2);
        size[node1] += size[node2];
        par[node2] = node1;
    }
};
