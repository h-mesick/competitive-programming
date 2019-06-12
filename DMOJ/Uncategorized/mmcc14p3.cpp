#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 5005;
int N, S, L, dis[MN], node[MN], par[MN];
vector<int> adj[MN];
bool vis[MN];

bool cmp(int u, int v) {
    return dis[u] > dis[v];
}

void dfs1(int u, int p) {
    par[u] = p;
    for (int v : adj[u]) {
        if (v ^ p) {
            dis[v] = dis[u] + 1;
            L = max(L, dis[v]);
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int p, int d) {
    if (!d) return;
    vis[u] = true;
    for (int v : adj[u])
        if (v ^ p)
            dfs2(v, u, d - 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> S;
    for (int i = 1; i <= N; i++) node[i] = i;
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1, 1);
    sort(node + 1, node + N + 1, cmp);
    int d = 0;
    for (; d <= L; d++) {
        memset(vis, false, sizeof vis);
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            int rt = node[i];
            if (vis[rt]) continue;
            for (int j = 0; j < d; j++)
                rt = par[rt];
            dfs2(rt, -1, d + 1);
            if (++cnt == S) break;
        }
        bool ret = true;
        for (int i = 1; i <= N; i++)
            if (!vis[i]) {
                ret = false;
                break;
            }
        if (ret) break;
    }
    cout << d << '\n';
    return 0;
}

