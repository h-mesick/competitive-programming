#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, X, cnt = 0;
map<int, int> tree;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X;
        int temp = 0;
        auto idx = tree.lower_bound(X);
        if (idx != tree.end()) temp = max(temp, idx->s + 1);
        if (idx != tree.begin()) temp = max(temp, (--idx)->s + 1);
        tree[X] = temp;
        cnt += temp;
        cout << cnt << '\n';
    }
    return 0;
}

