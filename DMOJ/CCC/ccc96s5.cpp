#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int T, N, a[MN], b[MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        int ret = 0;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < N; i++) cin >> b[i];
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++)
                if (b[j] >= a[i]) ret = max(ret, j - i);
                else break;
        }
        cout << "The maximum distance is " << ret << '\n';
    }
    return 0;
}