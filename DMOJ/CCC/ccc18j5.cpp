#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, dis[10005];
vector<int> adj[10005];

void dfs(int u) {
    for (int v : adj[u])
        if (dis[v] > dis[u] + 1)
            dis[v] = dis[u] + 1, dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        dis[i] = 0x3f3f3f3f;
        cin >> M;
        for (int j = 0, a; j < M; j++)
            cin >> a, adj[i].pb(a);
    }
    dis[1] = 0;
    dfs(1);
    bool vis = true;
    int ret = 0x3f3f3f3f;
    for (int i = 2; i <= N; i++) {
        if (dis[i] == 0x3f3f3f3f)
            vis = false;
        if (adj[i].empty())
            ret = min(ret, dis[i]);
    }
    cout << (vis ? "Y\n" : "N\n") << ret + 1 << '\n';
    return 0;
}