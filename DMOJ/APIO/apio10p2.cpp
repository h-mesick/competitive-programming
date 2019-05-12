#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, K, L, rt, ans, pre[MN];
map<int, int> adj[MN];

void dfs1(int u, int p, int d) {
    if (d > L)
        L = d, rt = u;
    pre[u] = p;
    for (auto v : adj[u]) {
        if (v.f ^ p)
            dfs1(v.f, u, d + 1);
    }
}

int dfs2(int u, int p) {
    int f = 0, s = 0;
    for (auto v : adj[u]) {
        if (v.f ^ p) {
            int d = dfs2(v.f, u) + v.s;
            if (d > f)
                f = d, s = f;
            else if (d > s)
                s = d;
        }
    }
    L = max(L, f + s);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1, a, b; i < N; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    dfs1(1, 0, 0);
    L = 0;
    dfs1(rt, 0, 0);
    ans = 2 * (N - 1) - L + 1;
    if (K == 1) {
        cout << ans << '\n';
        return 0;
    }
    for (int i = rt; pre[i]; i = pre[i]) {
        adj[i][pre[i]] = -1;
        adj[pre[i]][i] = -1;
    }
    L = 0;
    dfs2(1, 0);
    cout << ans - L + 1 << '\n';
    return 0;
}