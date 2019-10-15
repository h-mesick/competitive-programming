#pragma once
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

mt19937 g1(time(0));
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}
ll randlong(ll a,ll b){return uniform_int_distribution<ll>(a, b)(g1);}

ll exgcd(ll a, ll b, ll &x, ll &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    int d = exgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool diophantine(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
    g = exgcd(abs(a), abs(b), x0, y0);
    if(c % g)
        return 0;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return 1;
}

void shift(ll &x, ll &y, ll a, ll b, ll cnt){
    x += cnt * b;
    y -= cnt * a;
}

ll diophantine_cnt(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy){
    ll x, y, g;
    if(!diophantine(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;

    ll sign_a = a > 0 ? 1 : -1;
    ll sign_b = b > 0 ? 1 : -1;

    shift(x, y, a, b, (minx - x) / b);
    if(x < minx) shift(x, y, a, b, sign_b);
    if(x > maxx) return 0;
    ll lx1 = x;

    shift(x, y, a, b, (maxx - x) / b);
    if(x > maxx) shift(x, y, a, b, -sign_b);
    ll rx1 = x;

    shift(x, y, a, b, -(miny - y) / a);
    if(y < miny) shift(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    ll lx2 = x;

    shift(x, y, a, b, -(maxy - y) / a);
    if(y > maxy) shift(x, y, a, b, sign_a);
    ll rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    ll lx = max(lx1, lx2);
    ll rx = min(rx1, rx2);

    if(lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}
