#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, H, grid[1505][1505];
bool vis[1505][1505];

void dfs(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N || vis[i][j])
        return;
    vis[i][j] = true;
    if (abs(grid[i][j] - grid[i - 1][j]) <= H) dfs(i - 1, j);
    if (abs(grid[i][j] - grid[i + 1][j]) <= H) dfs(i + 1, j);
    if (abs(grid[i][j] - grid[i][j - 1]) <= H) dfs(i, j - 1);
    if (abs(grid[i][j] - grid[i][j + 1]) <= H) dfs(i, j + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> H;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];
    dfs(0, 0);
    cout << (vis[N - 1][N - 1] ? "yes" : "no") << '\n';
    return 0;
}
