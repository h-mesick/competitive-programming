#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int R, C, dis[21][21];
char grid[21][21];

void dfs(int i, int j, int d) {
    if (i < 0 || i >= R || j < 0 || j >= C || grid[i][j] == '*' || dis[i][j] <= d)
        return;
    dis[i][j] = d;
    if (grid[i][j] == '|')
        dfs(i - 1, j, d + 1), dfs(i + 1, j, d + 1);
    else if (grid[i][j] == '-')
        dfs(i, j - 1, d + 1), dfs(i, j + 1, d + 1);
    else
        dfs(i - 1, j, d + 1), dfs(i + 1, j, d + 1), dfs(i, j - 1, d + 1), dfs(i, j + 1, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> R >> C;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                cin >> grid[i][j];
        memset(dis, 0x3f, sizeof dis);
        dfs(0, 0, 1);
        cout << (dis[R - 1][C - 1] == 0x3f3f3f3f ? -1 : dis[R - 1][C - 1]) << '\n';
    }
    return 0;
}
