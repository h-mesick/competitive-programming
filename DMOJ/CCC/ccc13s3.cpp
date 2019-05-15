#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int T, G, S[5], ret;
bool vis[5][5];

void solve(int S[], int cnt) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (!vis[i][j] && i != j) {
                vis[i][j] = vis[j][i] = true;
                S[i] += 3, solve(S, cnt + 1), S[i] -= 3;
                S[j] += 3, solve(S, cnt + 1), S[j] -= 3;
                S[i]++, S[j]++, solve(S, cnt + 1), S[i]--, S[j]--;
                vis[i][j] = vis[j][i] = false;
                goto out;
            }
        }
    }
    out:;
    if (cnt == 6) {
        int mx = -1, idx = 0;
        for (int i = 1; i <= 4; i++) {
            if (S[i] > mx)
                mx = S[i], idx = i;
            else if (S[i] == mx)
                idx = -1;
        }
        if (idx == T)
            ret++;
    }
}

int main() {
    cin >> T >> G;
    for (int i = 0, a, b, sa, sb; i < G; i++) {
        cin >> a >> b >> sa >> sb;
        if (sa > sb) S[a] += 3;
        else if (sa < sb) S[b] += 3;
        else S[a]++, S[b]++;
        vis[a][b] = vis[b][a] = true;
    }
    solve(S, G);
    cout << ret << '\n';
    return 0;
}
