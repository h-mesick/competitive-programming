#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, h[505];
bool dp[2][25005];
set<int> vis;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];
    sort(h, h + N, greater<int>());
    dp[1][0] = true;
    vis.insert(h[1]);
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 25000; j++) {
            dp[i & 1][j] |= dp[(i - 1) & 1][j];
            for (int k : vis) {
                if (j < k - h[i]) continue;
                dp[i & 1][j] |= dp[(i - 1) & 1][j - k + h[i]];
            }
        }
        vis.insert(h[i]);
    }
    for (int i = 0; i <= 25000; i++)
        if (dp[(N - 1) & 1][i]) cout << i << " ";
    return 0;
}

