#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, t, x, y;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    vector<int> brooks(N);
    for (int i = 0; i < N; i++)
        cin >> brooks[i];
    while (cin >> t, t != 77) {
        if (t == 99) {
            cin >> x >> y;
            int temp = brooks[x - 1];
            brooks[x - 1] = temp * y / 100;
            brooks.insert(brooks.begin() + x, temp - temp * y / 100);
        } else {
            cin >> x;
            brooks[x - 1] += brooks[x];
            brooks.erase(brooks.begin() + x);
        }
    }
    for (int i : brooks)
        cout << i << " ";
    return 0;
}
