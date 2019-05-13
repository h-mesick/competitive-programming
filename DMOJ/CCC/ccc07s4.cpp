#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, dp[1000];
vector<int> adj[1000];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    int x, y;
    cin >> x >> y;
    while (x) {
        adj[x].pb(y);
        cin >> x >> y;
    }
    dp[1] = 1;
    for (int i = 1; i < N; i++)
        for (int j : adj[i])
            dp[j] += dp[i];
    cout << dp[N] << '\n';
    return 0;
}