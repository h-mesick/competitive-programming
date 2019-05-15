#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e4 + 5;
int N, M, in[MN];
vector<int> adj[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        in[b]++;
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        if (!in[i]) q.push(i), cnt++;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            in[v]--;
            if (!in[v]) q.push(v), cnt++;
        }
    }
    cout << (cnt == N ? "Y" : "N") << '\n';
    return 0;
}

