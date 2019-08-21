int adjMat[MAXN][MAXN];
int dist[MAXN][MAXN];

void FloydWarshall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else {
                dist[i][j] = (adjMat[i][j] > 0) ? adjMat[i][j] : INF;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
