#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int dp[1005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int C, M, N, K;
    cin >> C >> M;
    for (int i = 0; i < C; i++) {
        cin >> N >> K;
        for (int j = M; j >= K; j--) dp[j] = max(dp[j], dp[j - K] + N);
    }
    cout << dp[M] << '\n';
    return 0;
}
