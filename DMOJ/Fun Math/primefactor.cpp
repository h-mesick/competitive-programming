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

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    while (N--) {
        cin >> M;
        while (!(M & 1)) {
            cout << 2 << " ";
            M >>= 1;
        }
        for (int i = 3; i <= sqrt(M); i += 2) {
            while (M % i == 0) {
                cout << i << " ";
                M /= i;
            }
        }
        if (M > 1) cout << M << "\n";
        else cout << "\n";
    }
    return 0;
}