#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, X, Y, Z, dp[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> X >> Y >> Z;
    dp[X] = 1, dp[Y] = 1, dp[Z] = 1;
    for (int i = 1; i < N; i++) {
        if (dp[i]) {
            if (i + X <= N) dp[i + X] = dp[i] + 1;
            if (i + Y <= N) dp[i + Y] = dp[i] + 1;
            if (i + Z <= N) dp[i + Z] = dp[i] + 1;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}