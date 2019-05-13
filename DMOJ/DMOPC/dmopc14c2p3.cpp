#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, a[50005], b[50005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    sort(a, a + N);
    sort(b, b + N);
    ll ret = 0;
    for (int i = 0; i < N; i++) ret += a[i] * b[N - i - 1];
    cout << ret << '\n';
    return 0;
}
