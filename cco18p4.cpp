#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 105;
int R, C, K;
map<pii, int> mp;

int query(int i, int j) {
    if (mp.count({i, j})) return mp[{i, j}];
    int ret;
    cout << "? " << i << " " << j << endl;
    cin >> ret;
    return mp[{i, j}] = ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> R >> C >> K;
    int l1 = 1, l2 = 1, r1 = R, r2 = C, m1, m2;
    while (l1 < r1 || l2 < r2) {
        m1 = l1 + r1 >> 1, m2 = l2 + r2 >> 1;
        int c = query(m1, m2);
        if (l1 < r1) {
            int d = query(m1 + 1, m2);
            if (c < d) r1 = m1;
            else l1 = m1 + 1;
        }
        if (l2 < r2) {
            int r = query(m1, m2 + 1);
            if (c < r) r2 = m2;
            else l2 = m2 + 1;
        }
    }
    int ret = query(l1, l2);
    cout << "! " << ret << endl;
    return 0;
}