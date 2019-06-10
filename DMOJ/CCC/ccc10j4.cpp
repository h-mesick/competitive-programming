#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int a[20], dif[20];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    while (cin >> N, N) {
        for (int i = 0; i < N; i++) cin >> a[i];
        if (N == 1) {
            cout << "0\n";
            continue;
        }
        for (int i = 1; i < N; i++) dif[i] = a[i] - a[i - 1];
        int i, x = 1;
        while (true) {
            for (i = 1; i + x < N && dif[i] == dif[i + x]; i++);
            if (i + x >= N) break;
            x++;
        }
        cout << x << '\n';
    }
    return 0;
}

