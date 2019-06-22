#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 20;
int N, M, A, B, C;
vector<int> adj[1 << 20];
bool vis[1 << 20];
pii d[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int next(int cur) {
    int next = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int idx = i * M + j, cnt = 0;
            for (pii k : d) {
                int x = k.f, y = k.s;
                if (i + x < 0 || i + x >= N || j + y < 0 || j + y >= M) continue;
                cnt += (cur >> ((i + x) * M + (j + y))) & 1;
            }
            next |= ((cur >> idx) & 1 ? cnt >= A && cnt <= B : cnt > C) << idx;
        }
    }
    return next;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> A >> B >> C;
    for (int i = 0; i < (1 << (N * M)); i++)
        adj[next(i)].pb(i);
    char c;
    int st = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> c, st |= ((c == '*') << (i * M + j));
    queue<pii> q;
    q.push({0, st});
    while (!q.empty()) {
        int d = q.front().f, u = q.front().s;
        q.pop();
        if (adj[u].empty()) {
            cout << d << '\n';
            return 0;
        }
        for (int v : adj[u])
            if (!vis[v])
                vis[v] = true, q.push({d + 1, v});
    }
    cout << -1 << '\n';
    return 0;
}