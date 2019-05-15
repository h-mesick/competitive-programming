#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, a[20];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i], cout << a[i] << " ";
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++)
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                for (int k = 0; k < N; k++) cout << a[k] << " ";
                cout << '\n';
            }
    }
    return 0;
}