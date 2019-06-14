#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 55;
int R, C, flood[MN][MN], dis[MN][MN];
char grid[MN][MN];
pii d[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, st, ed;
queue<pii> q;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            flood[i][j] = INT_MAX;
            dis[i][j] = INT_MAX;
            if (grid[i][j] == 'S') st = {i, j};
            else if (grid[i][j] == 'D') ed = {i, j};
            else if (grid[i][j] == '*') q.push({i, j}), flood[i][j] = 0;
        }
    }
    while (!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();
        for (pii k : d) {
            int x = i + k.f, y = j + k.s;
            if (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != 'X' && grid[x][y] != 'D')
                if (flood[x][y] > flood[i][j] + 1)
                    flood[x][y] = flood[i][j] + 1, q.push({x, y});
        }
    }
    q.push(st);
    dis[st.f][st.s] = 0;
    while (!q.empty()) {
        int i = q.front().f, j = q.front().s;
        q.pop();
        for (pii k : d) {
            int x = i + k.f, y = j + k.s;
            if (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] != 'X')
                if (flood[x][y] > dis[i][j] + 1 && dis[x][y] > dis[i][j] + 1)
                    dis[x][y] = dis[i][j] + 1, q.push({x, y});
        }
    }
    if (dis[ed.f][ed.s] == INT_MAX) cout << "KAKTUS\n";
    else cout << dis[ed.f][ed.s] << '\n';
    return 0;
}