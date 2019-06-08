#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, par[MN];
vector<int> edges;

int find(int x) {
    if (x != par[x]) par[x] = find(par[x]);
    return par[x];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) par[i] = i;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        u = find(u), v = find(v);
        if (u != v)
            par[u] = v, edges.pb(i);
        if (edges.size() == N - 1) break;
    }
    if (edges.size() < N - 1) cout << "Disconnected Graph\n";
    else for (int i : edges) cout << i << '\n';
    return 0;
}
