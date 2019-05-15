#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
vector<int> adj[51];
bool friends[51];
int dis[51];

void add(int u, int v) {
    adj[u].pb(v), adj[v].pb(u);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    add(1, 6), add(2, 6), add(3, 4), add(3, 5), add(3, 6), add(3, 15);
    add(4, 5), add(4, 6), add(5, 6), add(6, 7), add(7, 8), add(8, 9);
    add(9, 10), add(9, 12), add(10, 11), add(11, 12), add(12, 13);
    add(13, 14), add(13, 15), add(16, 17), add(16, 18), add(17, 18);
    char t;
    int x, y;
    while (cin >> t, t != 'q') {
        if (t == 'i') {
            cin >> x >> y;
            if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end())
                add(x, y);
        } else if (t == 'd') {
            cin >> x >> y;
            auto it = find(adj[x].begin(), adj[x].end(), y);
            if (it != adj[x].end())
                adj[x].erase(it), adj[y].erase(find(adj[y].begin(), adj[y].end(), x));
        } else if (t == 'n') {
            cin >> x;
            cout << adj[x].size() << '\n';
        } else if (t == 'f') {
            cin >> x;
            int cnt = 0;
            memset(friends, false, sizeof friends);
            friends[x] = true;
            for (int i : adj[x])
                friends[i] = true;
            for (int i : adj[x])
                for (int j : adj[i])
                    if (!friends[j])
                        cnt++, friends[j] = true;
            cout << cnt << '\n';
        } else {
            cin >> x >> y;
            memset(dis, 0x3f, sizeof dis);
            dis[x] = 0;
            queue<int> q;
            q.push(x);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u])
                    if (dis[v] > dis[u] + 1)
                        dis[v] = dis[u] + 1, q.push(v);
            }
            if (dis[y] == 0x3f3f3f3f)
                cout << "Not connected" << '\n';
            else
                cout << dis[y] << '\n';
        }
    }
    return 0;
}

