#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;

bool mword(string a);

bool aword(string a) {
    return a == "A" || (a[0] == 'B' && a[a.size() - 1] == 'S' && mword(a.substr(1, a.size() - 2)));
}

bool mword(string a) {
    if (aword(a)) return true;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == 'N')
            if (aword(a.substr(0, i)) && mword(a.substr(i + 1, a.size() - i - 1))) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string monkey;
    while (cin >> monkey, monkey != "X")
        cout << (mword(monkey) ? "YES" : "NO") << '\n';
    return 0;
}