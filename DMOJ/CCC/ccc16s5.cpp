#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, a[MN], b[MN];
ll T;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> T;
    char c;
    for (int i = 0; i < N; i++) {
        cin >> c;
        a[i] = c == '1';
    }
    for (int i = 50; i >= 0; i--) {
        if ((T >> i) & 1) {
            int p = ((1LL << i)) % N;
            for (int j = 0; j < N; j++)
                b[j] = a[(j + p) % N] ^ a[(j - p + N) % N];
            for (int j = 0; j < N; j++)
                a[j] = b[j];
        }
    }
    for (int i = 0; i < N; i++)
        cout << a[i];
    cout << '\n';
    return 0;
}

