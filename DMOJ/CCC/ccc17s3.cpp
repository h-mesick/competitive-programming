#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, L[2005], H[4005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0, l; i < N; i++)
        cin >> l, L[l]++;
    for (int i = 1; i <= 2000; i++) {
        if (L[i]) {
            for (int j = i; j <= 2000; j++) {
                if (i == j)
                    H[i << 1] += L[i] >> 1;
                else
                    H[i + j] += min(L[i], L[j]);
            }
        }
    }
    int mx = 0, cnt = 0;
    for (int i = 1; i <= 4000; i++)
        if (H[i] > mx)
            mx = H[i], cnt = 1;
        else if (H[i] == mx)
            cnt++;
    cout << mx << " " << cnt << '\n';
    return 0;
}

