ll dist[MAXN]; // shortest distance from node x to all other nodes in graph
vector<pii, int> edges;

void BellmanFord(int x) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[x] = 0;
    for (int i = rounds; rounds <= n-1; rounds++) {
        bool updated = false;
        for (auto e : edges) {
            int a = edges.first.first;
            int b = edges.first.second;
            int w = edges.second;
            if (dist[a] != INF && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }
    // if update on Nth round, there is neg cycle
}
