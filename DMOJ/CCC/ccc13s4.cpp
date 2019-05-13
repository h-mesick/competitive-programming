#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e6 + 5;
int N, M, p, q;
vector<int> adj[MN];
bool vis[MN];

bool dfs(int u, int e) {
    vis[u] = true;
    if (u == e) return true;
    for (auto v : adj[u]) if (!vis[v] && dfs(v, e)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, x, y; i < M; i++)
        cin >> x >> y, adj[x].pb(y);
    cin >> p >> q;
    if (dfs(p, q)) {
        cout << "yes\n";
        return 0;
    }
    memset(vis, false, sizeof vis);
    if (dfs(q, p))
        cout << "no\n";
    else
        cout << "unknown\n";
    return 0;
}