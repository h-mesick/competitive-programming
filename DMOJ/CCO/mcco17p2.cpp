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
const int MN = 2e5 + 5;
int N, K, Q;
struct node {
  int l, r;
  ll v, lazy;
} t[4 * MN];

void push_down(int id) {
    if (t[id].lazy) {
        t[id].v += t[id].lazy;
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
        t[id].v = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void update(int id, int l, int r, ll v) {
    push_down(id);
    if (t[id].l > r || t[id].r < l) return;
    if (t[id].l >= l && t[id].r <= r) {
        t[id].lazy = v;
        push_down(id);
        return;
    }
    update(lc, l, r, v);
    update(rc, l, r, v);
    t[id].v = max(t[lc].v, t[rc].v);
}

ll query(int id, int l, int r) {
    push_down(id);
    if (t[id].l > r || t[id].r < l) return 0;
    if (t[id].l >= l && t[id].r <= r) return t[id].v;
    return max(query(lc, l, r), query(rc, l, r));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> K >> Q;
    build();
    for (int i = 0, q, l, r; i < Q; i++) {
        cin >> q >> l >> r;
        l++;
        if (!q) {
            update(1, max(l - K + 1, 1), l, r);
        } else {
            r++;
            cout << query(1, l, r) << '\n';
        }
    }
    return 0;
}