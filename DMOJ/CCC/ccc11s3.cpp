#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;

bool solve(int m, int x, int y) {
    if (m == 0) return false;
    int cur = (int) pow(5, m - 1);
    int i = x / cur, j = y / cur;
    if ((i >= 1 && i <= 3 && j == 0) || (i == 2 && j == 1)) return true;
    else if (((i == 1 || i == 3) && j == 1) || (i == 2 && j == 2)) return solve(m - 1, x % cur, y % cur);
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, m, x, y;
    cin >> T;
    while (T--)
        cin >> m >> x >> y, cout << (solve(m, x, y) ? "crystal" : "empty") << '\n';
    return 0;
}