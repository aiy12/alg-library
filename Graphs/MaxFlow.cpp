int capacity[MAXN][MAXN];
vector<int> adjList[MAXN];

int search(int src, int sink, vector<int>& par) {
    // 1-indexed
    for (int i = 0; i <= N; i++)
        par[i] = -1;
    par[src] = -2;
    
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(src, INT_MAX));
    
    while (!bfs.empty()) {
        int cur_node = bfs.front().first;
        int cur_flow = bfs.front().second;
        bfs.pop();
        
        for (int nxt : adjList[cur_node]) {
            if (par[nxt] == -1 && capacity[cur_node][nxt] > 0) {
                par[nxt] = cur_node;
                int nflow = min(cur_flow, capacity[cur_node][nxt]);
                if (nxt == sink)
                    return nflow;
                bfs.push(make_pair(nxt, nflow));
            }
        }
    }
    
    return 0;
}

int maxFlow(int src, int sink) {
    int flow = 0;
    vector<int> par(N);
    
    int nflow;
    while (nflow = search(src, sink, par)) {
        flow += nflow;
        int cur = sink;
        while (cur != src) {
            capacity[cur][par[cur]] += nflow;
            capacity[par[cur]][cur] -= nflow;
            cur = par[cur];
        }
    }
    
    return flow;
}
