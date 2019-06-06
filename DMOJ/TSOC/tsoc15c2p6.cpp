#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define lc (id << 1)
#define rc (id << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 3e4 + 5;
int N, Q, a[MN];
struct node {
  int l, r, m, lazy;
} t[4 * MN];

void push_down(int id) {
    if (t[id].lazy) {
        t[id].m = max(0, t[id].m + t[id].lazy);
        if (t[id].l ^ t[id].r) {
            t[lc].lazy += t[id].lazy;
            t[rc].lazy += t[id].lazy;
        }
        t[id].lazy = 0;
    }
}

void build(int id = 1, int l = 1, int r = N) {
    t[id].l = l, t[id].r = r;
    if (l == r) {
        t[id].m = a[l];
        t[id].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    t[id].m = min(t[lc].m, t[rc].m);
}

int query(int id, int l, int r, int v) {
    push_down(id);
    if (t[id].l > r || t[id].r < l) return INT_MAX;
    if (t[id].l >= l && t[id].r <= r) {
        t[id].lazy = v;
        push_down(id);
        return t[id].m;
    }
    int ret = min(query(lc, l, r, v), query(rc, l, r, v));
    t[id].m = min(t[lc].m, t[rc].m);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    build();
    for (int i = 0, l, r, v; i < Q; i++) {
        cin >> l >> r >> v;
        int ret = query(1, l, r, -v);
        cout << ret << " " << t[1].m << '\n';
    }
    return 0;
}
