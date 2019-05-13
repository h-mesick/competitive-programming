#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, dis[1005];
vector<pii> adj[1005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w}), adj[v].pb({u, w});
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        int d = q.top().f, u = q.top().s;
        q.pop();
        if (d > dis[u]) continue;
        for (auto e : adj[u]) {
            int v = e.f, w = e.s;
            if (dis[v] > dis[u] + w)
                dis[v] = dis[u] + w, q.push({dis[v], v});
        }
    }
    for (int i = 1; i <= N; i++)
        cout << (dis[i] == 0x3f3f3f3f ? -1 : dis[i]) << '\n';
    return 0;
}