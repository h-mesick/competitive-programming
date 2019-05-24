#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, Q, psa[500005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> psa[i], psa[i] += psa[i - 1];
    for (int i = 0, a, b; i < Q; i++)
        cin >> a >> b, cout << psa[N] - psa[b] + psa[a - 1] << '\n';
    return 0;
}