#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int N, num, ret;

struct connection {
  int a, b;

  bool operator<(const connection &c) const {
      return a == c.a ? b < c.b : a > c.a;
  }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    vector<connection> v;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        if (!a || !b)
            num++;
        else
            v.pb({a, b});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < v.size(); i++) {
        q.push(v[i].b);
        if (v[i].a > v.size() - i - 1 + num) {
            num++;
            ret += q.top(), q.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}