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
int a[1005][1005], cnt[1005][1005];
ll ret = 0;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> a[i][j];
            cnt[i][j] = 1;
            if (a[i][j] == a[i - 1][j])
                cnt[i][j] += cnt[i - 1][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int temp = cnt[i][j];
            for (int k = j; k <= M; k++) {
                if (a[i][j] != a[i][k]) break;
                temp = min(temp, cnt[i][k]);
                ret += temp;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
