#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int Q, psa[MN], x, y;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s >> Q;
    for (int i = 1; i <= s.length(); i++) {
        if (s[i - 1] == 'G') psa[i] = psa[i - 1] + 1;
        else psa[i] = psa[i - 1];
    }
    while (Q--)
        cin >> x >> y, cout << psa[y + 1] - psa[x] << '\n';
    return 0;
}

