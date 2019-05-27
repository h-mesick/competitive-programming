#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;

struct node {
  node *ch[2];
  int idx;

  node() {
      ch[0] = ch[1] = nullptr, idx = 1e9;
  }
};

int N, Q, q, mask = 1 << 30;
node *root;

void insert(node *cur, int x, int idx, int mask) {
    if (!mask) {
        cur->idx = min(cur->idx, idx);
        return;
    }
    int bit = (x & mask) > 0;
    if (!cur->ch[bit]) cur->ch[bit] = new node();
    insert(cur->ch[bit], x, idx, mask >> 1);
}

int query(node *cur, int x, int mask) {
    if (!mask) return cur->idx;
    int bit = (x & mask) > 0;
    if (cur->ch[bit]) return query(cur->ch[bit], x, mask >> 1);
    return query(cur->ch[!bit], x, mask >> 1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    root = new node();
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        insert(root, a, i, mask);
    }
    for (int i = 0, x; i < Q; i++) {
        cin >> x;
        q ^= x;
        cout << query(root, q, mask) << '\n';
    }
    return 0;
}

