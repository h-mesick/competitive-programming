#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int G, P;
set<int> gates;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> G >> P;
    for (int i = 1; i <= G; i++)
        gates.insert(-i);
    for (int i = 0, g; i < P; i++) {
        cin >> g;
        if (gates.lower_bound(-g) == gates.end()) {
            cout << i << '\n';
            return 0;
        }
        gates.erase(gates.lower_bound(-g));
    }
    cout << P << '\n';
    return 0;
}
