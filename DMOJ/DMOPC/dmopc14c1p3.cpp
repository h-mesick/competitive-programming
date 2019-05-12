#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int MN = 1e5 + 5;
int I, S, sum;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> I;
    int a;
    for (int i = 0; i < I; i++)
        cin >> a, sum += a;
    cin >> S;
    for (int i = 1; i <= S; i++)
        cin >> a, sum += a, cout << setprecision(4) << (double) sum / ++I << '\n';
    return 0;
}