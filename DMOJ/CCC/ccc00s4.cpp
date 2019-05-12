#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M;
vector<int> dp(5281, 10000);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    dp[0] = 0;
    for (int i = 0, a; i < M; i++) {
        cin >> a;
        for (int j = a; j <= N; j++)
            dp[j] = min(dp[j], dp[j - a] + 1);
    }
    if (dp[N] == 10000) cout << "Roberta acknowledges defeat." << '\n';
    else cout << "Roberta wins in " << dp[N] << " strokes." << '\n';
    return 0;
}