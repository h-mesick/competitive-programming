#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, M, D, par[MN], mx, cnt, days;

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

struct edge {
  int u, v, w;
  bool o;

  bool operator<(const edge e) const {
      return w < e.w || (w == e.w && o);
  }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> D;
    for (int i = 1; i <= N; i++) par[i] = i;
    vector<edge> edges;
    for (int i = 0, u, v, w; i < M; i++) {
        cin >> u >> v >> w;
        edges.pb({u, v, w, i < N - 1});
    }
    sort(edges.begin(), edges.end());
    for (edge e : edges) {
        int u = find(e.u), v = find(e.v);
        if (u ^ v) {
            par[u] = v;
            mx = e.w;
            cnt++;
            if (!e.o) days++;
            if (cnt == N - 1) break;
        }
    }
    if (D >= mx) {
        for (int i = 1; i <= N; i++) par[i] = i;
        for (edge e : edges) {
            int u = find(e.u), v = find(e.v);
            if (u ^ v) {
                if (e.w < mx || (e.w == mx && e.o)) par[u] = v;
                else if (e.w <= D && e.o) {
                    cout << days - 1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << days << '\n';
    return 0;
}