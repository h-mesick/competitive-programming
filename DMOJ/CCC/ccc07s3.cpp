#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, dis[10000];
vector<int> adj[10000];

void dfs(int u) {
    for (int v : adj[u])
        if (dis[v] > dis[u] + 1)
            dis[v] = dis[u] + 1, dfs(v);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x, y;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> x >> y, adj[x].pb(y);
    cin >> x >> y;
    while (x) {
        memset(dis, 0x3f, sizeof dis);
        dis[x] = 0;
        dfs(x);
        if (dis[y] == 0x3f3f3f3f) cout << "No\n";
        else cout << "Yes " << dis[y] - 1 << '\n';
        cin >> x >> y;
    }
    return 0;
}
