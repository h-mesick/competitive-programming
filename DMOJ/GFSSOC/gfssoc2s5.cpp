#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 5e5 + 5, MOD = 1e9 + 7;
int N, M, cnt, scc, disc[MN], low[MN], id[MN], a[MN], val[MN];
stack<int> st;
vector<int> adj1[MN], adj2[MN];
pii dp[MN][2];
bool ins[MN];

void tarjan(int u) {
    disc[u] = low[u] = cnt++;
    st.push(u), ins[u] = true;
    for (int v : adj1[u]) {
        if (!disc[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v])
            low[u] = min(low[u], disc[v]);
    }
    if (disc[u] == low[u]) {
        int v;
        do {
            v = st.top(), st.pop(), ins[v] = false;
            id[v] = scc, val[scc] += a[v];
        } while (v != u);
        scc++;
    }
}

pii dfs(int u, bool take) {
    if (dp[u][take].f != -1) return dp[u][take];
    if (u == id[N]) {
        if (take) return {val[u], 1};
        else return {0, 1};
    }
    pii ret = {INT_MIN, 0}, hold;
    for (int v : adj2[u]) {
        if (take) {
            hold = dfs(v, false);
            hold.f += val[u];
            if (hold.f > ret.f) ret = hold;
            else if (hold.f == ret.f) ret.s = (ret.s + hold.s) % MOD;
        }
        hold = dfs(v, true);
        if (hold.f > ret.f) ret = hold;
        else if (hold.f == ret.f) ret.s = (ret.s + hold.s) % MOD;
    }
    return dp[u][take] = ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 0, u, v; i < M; i++) {
        cin >> u >> v;
        adj1[u].pb(v);
    }
    for (int i = 1; i <= N; i++)
        if (!disc[i]) tarjan(i);
    for (int i = 1; i <= N; i++)
        for (int j : adj1[i])
            if (id[i] != id[j]) adj2[id[i]].pb(id[j]);
    pii ret = dfs(id[1], true);
    cout << ret.f << " " << ret.s << '\n';
    return 0;
}