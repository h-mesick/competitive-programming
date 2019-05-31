#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
ll N, M;
int ret = 0;
bool p[100005], q[20000005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (ll i = 2; i * i <= M; i++) {
        if (!p[i]) {
            ll temp = ((ll) (N / i)) * i;
            if (temp < N)
                temp += i;
            if (temp == i)
                temp += i;
            for (ll j = temp; j <= M; j += i)
                q[j - N] = true;
            for (ll j = i; j * j <= M; j += i)
                p[j] = true;
        }
    }
    for (ll i = max(N, 2LL); i < M; i++)
        if (!q[i - N]) ret++;
    cout << ret << '\n';
    return 0;
}