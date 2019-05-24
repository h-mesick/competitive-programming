#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N;
vector<int> adj[6];

int solve(int n) {
    int ret = 1;
    for (int i : adj[n])
        ret *= solve(i) + 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 1, j; i < N; i++)
        cin >> j, adj[j].pb(i);
    cout << solve(N) << '\n';
    return 0;
}

