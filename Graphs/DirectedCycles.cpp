// Finds all cycles in directed graph in O(|V + E|) time and O(|V|) space

int n, m;
vector<int> adj[MAXN];
vector<vector<int>> cycles;
 
void printCycle(stack<int>& stk, int v) {
    if (stk.size() == 0) return;
    stack<int> stk2;
    stk2.push(stk.top());
    stk.pop();
    while (!stk.empty() && stk2.top() != v) {
        stk2.push(stk.top());
        stk.pop();
    }
 
    vector<int> cyc;
    while (!stk2.empty()) {
        cyc.push_back(stk2.top());
        stk.push(stk2.top());
        stk2.pop();
    }
 
    cycles.push_back(cyc);
}
 
void processDFS(stack<int>& stk, vector<int>& visited) {
    for (int v : adj[stk.top()]) {
        if (visited[v] == 1) {
            printCycle(stk, v);
        } else if (visited[v] == 0) {
            stk.push(v);
            visited[v] = 1;
            processDFS(stk, visited);
        }
    }
    visited[stk.top()] = 2;
    stk.pop();
}
 
void findCycles() {
    vector<int> visited(n + 1);
    for (int i = 1; i <= n; i++) visited[i] = 0;
 
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            stack<int> stk;
            stk.push(i);
            visited[i] = 1;
            processDFS(stk, visited);
        }
    }
}
