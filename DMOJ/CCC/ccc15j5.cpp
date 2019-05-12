#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, K, dp[251][251];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (i < j) continue;
            if (i == j || j == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    }
    cout << dp[N][K] << '\n';
    return 0;
}