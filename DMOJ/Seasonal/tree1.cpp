#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int adj[4];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cnt = 0, a;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            cin >> a, cnt += a;
            if (a) adj[i]++;
        }
    if (cnt != 6) cout << "No\n";
    else {
        bool flag = true;
        for (int i = 0; i < 4; i++)
            if(!adj[i]){
                flag = false;
                break;
            }
        cout << (flag ? "Yes" : "No") << '\n';
    }
    return 0;
}