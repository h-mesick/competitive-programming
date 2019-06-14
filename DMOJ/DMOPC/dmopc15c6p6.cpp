#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1505;
int N, M, K;
bitset<MN> adj[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
    }
    for (int u = 1; u <= N; u++) {
        bitset<MN> vis, temp;
        vis[u] = true;
        for (int i = 0; i < K; i++) {
            temp = vis;
            for (int v = 1; v <= N; v++)
                if (temp[v])
                    vis |= adj[v];
        }
        cout << vis.count() << '\n';
    }
    return 0;
}