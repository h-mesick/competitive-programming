#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 105;
int N, M, dis[MN][MN];
char temp[MN][MN], grid[MN][MN];

void dfs(int i, int j, int d) {
    if (i < 0 || i >= N || j < 0 || j >= M || temp[i][j] == 'W' || (dis[i][j] != -1 && d >= dis[i][j]))
        return;
    dis[i][j] = d;
    if (grid[i][j] == 'L') dfs(i, j - 1, d);
    else if (grid[i][j] == 'R') dfs(i, j + 1, d);
    else if (grid[i][j] == 'U') dfs(i - 1, j, d);
    else if (grid[i][j] == 'D') dfs(i + 1, j, d);
    else {
        dfs(i, j - 1, d + 1);
        dfs(i, j + 1, d + 1);
        dfs(i - 1, j, d + 1);
        dfs(i + 1, j, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pii st;
    vector<pii> cameras, locations;
    memset(dis, -1, sizeof dis);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j], temp[i][j] = grid[i][j];
            if (grid[i][j] == 'S')
                st = {i, j};
            else if (grid[i][j] == '.')
                locations.pb({i, j});
            else if (grid[i][j] == 'C')
                cameras.pb({i, j});
        }
    }
    for (auto c : cameras) {
        int x = c.f, y = c.s;
        for (int i = x; i < N; i++) {
            if (grid[i][y] == 'W') break;
            if (grid[i][y] == 'S' || grid[i][y] == '.') temp[i][y] = 'W';
        }
        for (int i = x - 1; i >= 0; i--) {
            if (grid[i][y] == 'W') break;
            if (grid[i][y] == 'S' || grid[i][y] == '.') temp[i][y] = 'W';
        }
        for (int i = y; i < M; i++) {
            if (grid[x][i] == 'W') break;
            if (grid[x][i] == 'S' || grid[x][i] == '.') temp[x][i] = 'W';
        }
        for (int i = y - 1; i >= 0; i--) {
            if (grid[x][i] == 'W') break;
            if (grid[x][i] == 'S' || grid[x][i] == '.') temp[x][i] = 'W';
        }
    }
    dfs(st.f, st.s, 0);
    for (auto l : locations)
        cout << dis[l.f][l.s] << '\n';
    return 0;
}