#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
vector<string> v;

void perm(string cur, string ret) {
    if (cur.length() == 0) v.pb(ret);
    else {
        for (int i = 0; i < cur.length(); i++)
            perm(cur.substr(0, i) + cur.substr(i + 1), ret + cur[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a;
    cin >> a;
    perm(a, "");
    sort(v.begin(), v.end());
    for (string s : v) cout << s << '\n';
    return 0;
}

