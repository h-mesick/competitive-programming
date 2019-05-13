#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int R, C, K, grid[26][26];
bool cat[26][26];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> R >> C >> K;
    for (int i = 0, x, y; i < K; i++)
        cin >> x >> y, cat[x][y] = 1;
    grid[1][1] = 1;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (!cat[i][j])
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1];
    cout << grid[R][C] << '\n';
    return 0;
}
