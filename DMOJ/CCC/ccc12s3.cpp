#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, freq[1005], temp[1005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0, r; i < N; i++)
        cin >> r, freq[r]++, temp[r]++;
    sort(temp, temp + 1001);
    int f = temp[1000], s = temp[999];
    int mi = 0, mx = 0;
    if (f == s) {
        for (int i = 1; i <= 1000; i++)
            if (freq[i] == f) {
                mi = i;
                break;
            }
        for (int i = 1000; i >= 1; i--)
            if (freq[i] == f) {
                mx = i;
                break;
            }
        cout << mx - mi << '\n';
    } else {
        vector<int> v1, v2;
        for (int i = 1; i <= 1000; i++)
            if (freq[i] == s)
                v1.pb(i);
        for (int i = 1; i <= 1000; i++)
            if (freq[i] == f) {
                mi = i;
                break;
            }
        for (int i : v1)
            mx = max(mx, abs(mi - i));
        cout << mx << '\n';
    }
    return 0;
}
