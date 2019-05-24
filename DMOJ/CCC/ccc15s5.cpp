#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, A[3005], B[105], dp[3005][105][105][2];

int solve(int i, int l, int r, bool t) {
    int &ret = dp[i][l][r][t];
    if (ret) return ret;
    if (i == N) {
        if (l <= r) {
            if (t) return ret = B[r] + solve(i, l, r - 1, 0);
            else return ret = solve(i, l + 1, r, 1);
        }
        return ret = 0;
    }
    if (t) {
        ret = max(solve(i, l, r, 0), A[i] + solve(i + 1, l, r, 0));
        if (l <= r) ret = max(ret, B[r] + solve(i, l, r - 1, 0));
    } else {
        ret = solve(i + 1, l, r, 1);
        if (l <= r) ret = max(ret, solve(i, l + 1, r, 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(B, B + M);
    cout << solve(0, 0, M - 1, 1);
    return 0;
}