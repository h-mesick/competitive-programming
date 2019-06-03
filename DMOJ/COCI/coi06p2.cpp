#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, Q, cnt, disc[MN], low[MN], dep[MN], fin[MN];
vector<int> adj[MN], children[MN];

void dfs(int u, int p, int d) {
    disc[u] = low[u] = ++cnt, dep[u] = d;
    for (int v : adj[u]) {
        if (v ^ p) {
            if (!disc[v]) {
                dfs(v, u, d + 1);
                low[u] = min(low[u], low[v]);
                children[u].pb(v);
            } else
                low[u] = min(low[u], disc[v]);
        }
    }
    fin[u] = ++cnt;
}

bool in_subtree(int u, int v) {
    return disc[u] <= disc[v] && fin[v] <= fin[u];
}

int find_child(int u, int v) {
    int lo = 0, hi = children[u].size() - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (disc[v] > fin[children[u][mid]])
            lo = mid + 1;
        else if (disc[children[u][mid]] > fin[v])
            hi = mid - 1;
        else
            break;
    }
    return children[u][mid];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    dfs(1, 0, 0);
    cin >> Q;
    for (int i = 0, t, a, b, c, d; i < Q; i++) {
        bool ret;
        cin >> t >> a >> b;
        if (t == 1) {
            cin >> c >> d;
            if (in_subtree(d, c)) swap(d, c);
            ret = (dep[d] != dep[c] + 1) || (low[d] < disc[d]) || (in_subtree(d, a) == in_subtree(d, b));
        } else {
            cin >> c;
            if (!in_subtree(c, a) && !in_subtree(c, b)) ret = true;
            else if (in_subtree(c, a) && in_subtree(c, b)) {
                int e = find_child(c, a), f = find_child(c, b);
                ret = (e == f) || (low[e] < disc[c] && low[f] < disc[c]);
            } else {
                if (in_subtree(c, b)) swap(a, b);
                int e = find_child(c, a);
                ret = low[e] < disc[c];
            }
        }
        cout << (ret ? "yes" : "no") << '\n';
    }
    return 0;
}