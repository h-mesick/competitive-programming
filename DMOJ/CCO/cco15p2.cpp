#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define f first
#define s second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
const int MN = 20;
vector<pii> adj[MN];
int dp[MN][1 << MN];
int N, M;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    queue<pii> q;
    q.push({1, 0});
    while (!q.empty()) {
        int vis = q.front().f, u = q.front().s;
        q.pop();
        for (pii e : adj[u]) {
            int v = e.f, w = e.s;
            if (vis & (1 << v)) continue;
            if (dp[v][vis | (1 << v)] < dp[u][vis] + w) {
                dp[v][vis | (1 << v)] = dp[u][vis] + w;
                q.push({vis | (1 << v), v});
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < (1 << N); i++)
        ret = max(ret, dp[N - 1][i]);
    cout << ret << '\n';
    return 0;
}