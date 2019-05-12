#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 105;
int dis[10][10];
int u, v, w, x;

void dfs(int i, int j, int d) {
    if (i < 1 || i > 8 || j < 1 || j > 8 || dis[i][j] <= d) return;
    dis[i][j] = d;
    dfs(i - 2, j + 1, d + 1);
    dfs(i - 1, j + 2, d + 1);
    dfs(i + 1, j + 2, d + 1);
    dfs(i + 2, j + 1, d + 1);
    dfs(i + 2, j - 1, d + 1);
    dfs(i + 1, j - 2, d + 1);
    dfs(i - 1, j - 2, d + 1);
    dfs(i - 2, j - 1, d + 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dis, 9, sizeof dis);
    cin >> u >> v >> w >> x;
    dfs(u, v, 0);
    cout << dis[w][x];
    return 0;
}