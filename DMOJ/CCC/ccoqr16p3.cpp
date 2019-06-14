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
ll ret;
vector<pii> blocks;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 0, r, c; i < M; i++) {
        cin >> r >> c;
        blocks.pb({c, N - r + 1});
    }
    sort(blocks.begin(), blocks.end());
    int cur = 0, idx = 0;
    for (int i = 1; i <= N; i++) {
        while (i == blocks[idx].f) idx++;
        if (i == blocks[idx - 1].f) cur = max(cur, blocks[idx - 1].s);
        if (cur) ret += cur, cur--;
    }
    cout << ret << '\n';
    return 0;
}

