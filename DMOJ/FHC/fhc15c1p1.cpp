#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e7 + 5;
int cnt[MN];
vector<int> v[10];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int i = 2; i <= MN; i++) {
        if (!cnt[i])
            for (int j = i; j <= MN; j += i) cnt[j]++;
        v[cnt[i]].pb(i);
    }
    for (int t = 1, A, B, K; t <= T; t++) {
        cin >> A >> B >> K;
        cout << "Case #" << t << ": "
             << lower_bound(v[K].begin(), v[K].end(), B + 1) - upper_bound(v[K].begin(), v[K].end(), A - 1) << '\n';
    }
    return 0;
}