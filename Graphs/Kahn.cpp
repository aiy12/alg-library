// Note: Graph must be DAG for valid topological sorting to exist

vector<int> adjList[MAXN];
int inDeg[MAXN];
bool visited[MAXN];

vector<int> topoSort() {
    vector<int> order;
    queue<int> bfs;
    
    // might need to update if 1-indexed
    for (int node = 0; node < n; node++) {
        if (inDeg[node] == 0)
            bfs.push(node);
    }
    
    while (!bfs.empty()) {
        int curNode = bfs.front();
        bfs.pop();

        if (visited[curNode]) break;
        visited[curNode] = true;
        order.push_back(curNode);
        
        for (int adjNode : adjList[curNode]) {
            inDeg[adjNode]--;
            if (inDeg[adjNode] == 0)
                bfs.push(adjNode);
        }
    }
    
    return order;
}
