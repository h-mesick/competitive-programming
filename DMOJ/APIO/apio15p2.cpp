#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 3e4 + 5;
int N, M, st, ed, dis[MN];
vector<int> adj[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, b, p; i < M; i++) {
        cin >> b >> p;
        adj[b].pb(p);
        if (i == 0)
            st = b;
        else if (i == 1)
            ed = b;
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    memset(dis, 0x3f, sizeof dis);
    dis[st] = 0;
    q.push({0, st});
    while (!q.empty()) {
        int d = q.top().f, u = q.top().s;
        q.pop();
        if (u == ed) {
            cout << dis[ed] << '\n';
            return 0;
        }
        if (d > dis[u]) continue;
        for (int p : adj[u]) {
            for (int i = 1; u + i * p < N; i++) {
                int v = u + i * p;
                if (dis[v] > dis[u] + i)
                    dis[v] = dis[u] + i, q.push({dis[v], v});
            }
            for (int i = 1; u - i * p >= 0; i++) {
                int v = u - i * p;
                if (dis[v] > dis[u] + i)
                    dis[v] = dis[u] + i, q.push({dis[v], v});
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}