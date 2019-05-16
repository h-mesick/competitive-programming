#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, L, cnt, rt;
vector<int> adj[MN];
bool pho[MN], vis[MN];

void dfs1(int u, int p) {
    vis[u] = pho[u];
    for (int v : adj[u])
        if (v ^ p)
            dfs1(v, u), vis[u] |= vis[v];
    if (vis[u])
        cnt++;
}

void dfs2(int u, int p, int d) {
    if (d > L)
        L = d, rt = u;
    for (int v : adj[u])
        if (v ^ p && vis[v])
            dfs2(v, u, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> rt, pho[rt] = true;
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs1(rt, -1);
    dfs2(rt, -1, 0);
    dfs2(rt, -1, 0);
    cout << 2 * (cnt - 1) - L << '\n';
    return 0;
}