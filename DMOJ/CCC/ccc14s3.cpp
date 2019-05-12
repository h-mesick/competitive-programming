#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int T, N, cur;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        stack<int> mount, branch;
        for (int i = 0, a; i < N; i++)
            cin >> a, mount.push(a);
        cur = 1;
        while (!mount.empty()) {
            if (cur == mount.top()) cur++, mount.pop();
            else if (!branch.empty() && cur == branch.top()) cur++, branch.pop();
            else branch.push(mount.top()), mount.pop();
        }
        while (!branch.empty()) {
            if (cur == branch.top()) cur++, branch.pop();
            else {
                cout << "N\n";
                goto end;
            }
        }
        cout << "Y\n";
        end:;
    }
    return 0;
}
