#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int I, N, J, psa[MN], a, b, k, cnt;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> I >> N >> J;
    while (cin >> a >> b >> k, --J)
        psa[a] += k, psa[b + 1] -= k;
    for (int i = 1; i <= I; i++) {
        psa[i] += psa[i - 1];
        if (psa[i] < N) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}