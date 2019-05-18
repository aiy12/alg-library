// Solution to https://codeforces.com/contest/20/problem/C (C. Dijkstra?)

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

#define mp make_pair
#define pb push_back

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int pre[MAXN];
bool vis[MAXN];
vector<pair<int, ll>> adj[MAXN];
priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; ll w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
    }
    pq.push(mp(0LL, mp(1, 0)));
    pre[1] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (vis[cur.second.first]) continue;
        vis[cur.second.first] = true;
        pre[cur.second.first] = cur.second.second;
        if (cur.second.first == n) {
            break;
        }
        for (auto nxt : adj[cur.second.first]) {
            pq.push(mp(cur.first + nxt.second, mp(nxt.first, cur.second.first)));
        }
    }
    if (pre[n] == 0) {
        cout << -1;
    } else {
        vector<int> ans;
        while (pre[n] != 0) {
            ans.pb(n);
            n = pre[n];
        }
        reverse(ans.begin(), ans.end());
        cout << 1 << " ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
}
