#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e6 + 5;
struct query {
  char c;
  int a, b;
} q[MN];
int N, bit[MN], id[MN], rating[MN];
vector<int> x, r;
unordered_map<int, int> to_id, from_id, from_rating;

void update(int x, int v) {
    for (; x < MN; x += x & -x)
        bit[x] += v;
}

int query(int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        char temp;
        cin >> temp;
        if (temp == 'N' || temp == 'M')
            q[i].c = temp, cin >> q[i].a >> q[i].b, x.pb(q[i].a), r.pb(q[i].b);
        else
            q[i].c = temp, cin >> q[i].a;
    }
    sort(x.begin(), x.end());
    sort(r.begin(), r.end());
    int cnt = 1, tot = 0;
    for (int i : x) {
        from_id[i] = cnt;
        to_id[cnt++] = i;
    }
    cnt = 1;
    for (int i : r) {
        from_rating[i] = cnt++;
    }
    for (int i = 0; i < N; i++) {
        if (q[i].c == 'N') {
            int cur = from_id[q[i].a];
            id[cur] = from_rating[q[i].b];
            rating[from_rating[q[i].b]] = cur;
            update(id[cur], 1);
            tot++;
        } else if (q[i].c == 'M') {
            int cur = from_id[q[i].a];
            update(id[cur], -1);
            id[cur] = from_rating[q[i].b];
            rating[from_rating[q[i].b]] = cur;
            update(id[cur], 1);
        } else {
            int lo = 1, hi = r.size();
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (tot - query(mid) >= q[i].a)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            cout << to_id[rating[lo]] << '\n';
        }
    }
    return 0;
}