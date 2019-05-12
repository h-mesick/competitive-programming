#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, R, C, ret, cnt;
bool grid[65][65];

void dfs(int i, int j) {
    if (i < 0 || i >= R || j < 0 || j >= C || !grid[i][j]) return;
    grid[i][j] = 0, cnt++;
    dfs(i + 1, j), dfs(i - 1, j), dfs(i, j + 1), dfs(i, j - 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> R >> C;
    char c;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> c, grid[i][j] = c == '.';
    vector<int> rooms;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j])
                cnt = 0, dfs(i, j), rooms.pb(cnt);
    sort(rooms.rbegin(), rooms.rend());
    for (int i : rooms)
        if (i > N) break;
        else ret++, N -= i;
    cout << ret << (ret == 1 ? " room, " : " rooms, ") << N << " square metre(s) left over" << '\n';
    return 0;
}

