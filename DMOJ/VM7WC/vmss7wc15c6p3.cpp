#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 4e5 + 5;
int N, a[MN], ret = INT_MIN;
vector<int> adj[MN];

void dfs(int u) {
    for (int v : adj[u])
        dfs(v), a[u] += a[v];
    ret = max(ret, a[u]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    dfs(1);
    cout << ret << '\n';
    return 0;
}