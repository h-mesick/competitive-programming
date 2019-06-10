#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
bool adj[26][26], vis[26];
int ret;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string ed;
    vector<string> edges;
    while (cin >> ed, ed != "**") {
        adj[ed[0] - 'A'][ed[1] - 'A'] = adj[ed[1] - 'A'][ed[0] - 'A'] = true;
        edges.pb(ed);
    }
    for (string e : edges) {
        adj[e[0] - 'A'][e[1] - 'A'] = adj[e[1] - 'A'][e[0] - 'A'] = false;
        memset(vis, false, sizeof vis);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < 26; v++)
                if (adj[u][v] && !vis[v])
                    vis[v] = true, q.push(v);
        }
        if (!vis[1]) cout << e << '\n', ret++;
        adj[e[0] - 'A'][e[1] - 'A'] = adj[e[1] - 'A'][e[0] - 'A'] = true;
    }
    cout << "There are " << ret << " disconnecting roads." << '\n';
    return 0;
}