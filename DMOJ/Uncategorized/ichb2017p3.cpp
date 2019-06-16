#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define lc (rt << 1)
#define rc (rt << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, Q; ll a[MN];
struct node {
  int l, r;
  ll v;
} t[4 * MN];

void push_up(int rt) {
    t[rt].v = t[lc].v & t[rc].v;
}

void build(int rt = 1, int l = 1, int r = N) {
    t[rt].l = l, t[rt].r = r;
    if (l == r) {
        t[rt].v = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    push_up(rt);
}

void update(int rt, int i, ll v) {
    if (t[rt].l > i || t[rt].r < i) return;
    if (t[rt].l == t[rt].r) {
        t[rt].v = v;
        return;
    }
    update(lc, i, v);
    update(rc, i, v);
    push_up(rt);
}

ll query(int rt, int l, int r) {
    if (t[rt].l > r || t[rt].r < l) return -1;
    if (t[rt].l >= l && t[rt].r <= r) return t[rt].v;
    return query(lc, l, r) & query(rc, l, r);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> a[i];
    build();
    char c;
    int x, y;
    ll val;
    while (Q--) {
        cin >> c;
        if (c == 'U') {
            cin >> x >> val;
            update(1, x, val);
        } else {
            cin >> x >> y >> val;
            cout << (val & query(1, x, y)) << '\n';
        }
    }
    return 0;
}