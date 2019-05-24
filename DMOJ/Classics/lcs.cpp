#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, a[1001], b[1001], dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= M; i++) cin >> b[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << dp[N][M] << '\n';
    return 0;
}

