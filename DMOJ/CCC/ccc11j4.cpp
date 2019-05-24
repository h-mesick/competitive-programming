#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    bool grid[402][202];
    for (int i = 1; i <= 3; ++i) {
        grid[200][i] = true;
        grid[203][i + 2] = true;
        grid[205][i + 2] = true;
        grid[199][i + 4] = true;
        grid[200 + i][3] = true;
        grid[204 + i][3] = true;
    }
    for (int i = 1; i <= 5; ++i)
        grid[207][2 + i] = true;
    for (int i = 1; i <= 7; ++i)
        grid[200 + i][7] = true;
    int i = 199, j = 5;
    bool flag;
    char c;
    int d;
    while (cin >> c >> d, c != 'q') {
        flag = false;
        if (c == 'u') {
            for (int k = 1; k <= d; ++k) {
                if (grid[i][--j]) flag = true;
                grid[i][j] = true;
            }
        } else if (c == 'd') {
            for (int k = 1; k <= d; ++k) {
                if (grid[i][++j]) flag = true;
                grid[i][j] = true;
            }
        } else if (c == 'l') {
            for (int k = 1; k <= d; ++k) {
                if (grid[--i][j]) flag = true;
                grid[i][j] = true;
            }
        } else {
            for (int k = 1; k <= d; ++k) {
                if (grid[++i][j]) flag = true;
                grid[i][j] = true;
            }
        }
        cout << i - 200 << " " << -j << " " << (flag ? "DANGER" : "safe") << '\n';
        if (flag) break;
    }
    return 0;
}