#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int K, N, M, A, B, dis[2005][205];

struct edge {
  int u, t, h;
};

vector<edge> adj[2005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> K >> N >> M;
    for (int i = 0, a, b, t, h; i < M; i++) {
        cin >> a >> b >> t >> h;
        adj[a].pb({b, t, h}), adj[b].pb({a, t, h});
    }
    cin >> A >> B;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, 0x3f, sizeof dis);
    dis[A][0] = 0;
    q.push({0, A});
    while (!q.empty()) {
        int d = q.top().f, u = q.top().s;
        q.pop();
        for (auto e : adj[u]) {
            int v = e.u, t = e.t, h = e.h;
            if (d + h < K && dis[v][d + h] > dis[u][d] + t)
                dis[v][d + h] = dis[u][d] + t, q.push({d + h, v});
        }
    }
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < K; i++)
        ret = min(ret, dis[B][i]);
    cout << (ret == 0x3f3f3f3f ? -1 : ret) << '\n';
    return 0;
}