#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a;
    int K;
    cin >> a >> K;
    deque<char> q, ret;
    for (char c : a)
        q.pb(c), ret.pb(c);
    for (int i = K; i < a.length(); i++) {
        char c = q.front();
        q.pop_front(), q.pb(a[i]);
        if (q.front() < c && q < ret)
            ret = q;
    }
    ret = min(ret, q);
    for (int i = 0; i < K; i++)
        cout << ret[i];
    return 0;
}
