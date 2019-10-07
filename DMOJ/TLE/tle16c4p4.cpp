#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, Q, rt, cnt;
vector<pii> adj[MN];
ll L, R, dis[MN], mn, mx;
bool vis[MN];

void dfs(int u, int p, ll d, bool f) {
    vis[u] = true;
    if (d > L) rt = u, L = d;
    if (f) R = min(R, max(d, dis[u]));
    else dis[u] = d;
    for (pii e : adj[u]) {
        int v = e.first, w = e.second;
        if (v ^ p) dfs(v, u, w + d, f);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> Q;
    for (int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            rt = i, L = 0, R = LONG_MAX;
            dfs(i, 0, 0, 0);
            L = 0;
            dfs(rt, 0, 0, 0);
            dfs(rt, 0, 0, 1);
            mx += L + 1;
            if (R > mn) mn = R, cnt = 1;
            else if (R == mn) cnt++;
        }
    }
    if (Q == 1) cout << mx - 1 << '\n';
    else cout << (cnt == 1 ? mn : mn + 1) << '\n';
    return 0;
}
