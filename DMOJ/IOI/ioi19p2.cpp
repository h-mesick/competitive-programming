#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1;

vector<int> adj[MM], adjr[MM], ans;
int sz[MM], dfn[MM], low[MM], t, par[MM];
int a, b, c, first = -1, purple, aa = 1, ab = 2, ac = 3;

void fill(int cur, int &rem, int v){
    if(!rem || ans[cur])
        return;
    ans[cur] = v;
    rem--;
    for(int u: adjr[cur]){
        if(dfn[u] > dfn[cur])
            fill(u, rem, v);
    }
}

void tar(int cur, int pre){
    if(cur)
        par[cur] = pre;
    
    dfn[cur] = low[cur] = ++t;
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        if(!dfn[u]){
            tar(u, cur);
            low[cur] = min(low[cur], low[u]);
            adjr[cur].push_back(u);
            adjr[u].push_back(cur);
        }
        else
            low[cur] = min(low[cur], dfn[u]);
    }
}

int dfs(int cur, int pre){
    sz[cur] = 1;
    
    for(int u: adjr[cur]){
        if(u == pre)
            continue;
        sz[cur] += dfs(u, cur);
    }
    if(first == -1 && sz[cur] >= a)
        first = cur;
    
    return sz[cur];
}

vector<int> find_split(int n, int ia, int ib, int ic, vector<int> p, vector<int> q){
    a = ia, b = ib, c = ic;
    ans.resize(n);
    for(int i = 0; i < n; i++)
        ans[i] = 0;
    
    for(int i = 0; i < p.size(); i++){
        adj[p[i]].push_back(q[i]);
        adj[q[i]].push_back(p[i]);
    }
    
    if(a > b)
        swap(a, b), swap(aa, ab);
    if(b > c)
        swap(b, c), swap(ab, ac);
    if(a > b)
        swap(a, b), swap(aa, ab);
    
    assert(a <= b && b <= c);
    
    tar(0, -1);
    dfs(0, -1);
    
    assert(first != -1);
    
    purple = 0;
    for(int u: adjr[first]){
        if(dfn[u] > dfn[first] && low[u] >= dfn[first])
            purple += sz[u];
    }
    if(purple >= b+c)
        return ans;
    
    if(purple >= b){
        ans[first] = ab;
        b--;
        for(int u: adjr[first]){
            if(dfn[u] > dfn[first] && low[u] >= dfn[first])
                fill(first, b, ab);
        }
        fill(par[first], a, aa);
    }
    else{
        ans[first] = aa;
        a--;
        for(int u: adjr[first]){
            if(dfn[u] > dfn[first] && low[u] >= dfn[first])
                fill(first, a, aa);
        }
        
        for(int u: adjr[first]){
            if(dfn[u] > dfn[first])
                fill(u, a, aa);
        }
        fill(par[first], b, ab);
    }
    
    for(int &i: ans){
        if(!i)
            i = ac;
    }
    
    return ans;
}

#ifndef ONLINE_JUDGE
int main(){
    
    auto out = find_split(9, 4, 2, 3, {0, 0, 0, 0, 0, 0, 1, 3, 4, 5}, {1, 2, 3, 4, 6, 8, 7, 7, 5, 6});
    //auto out = find_split(6, 2, 2, 2, {0, 0, 0, 0, 0}, {1, 2, 3, 4, 5});
    for(int i: out)
        printf("%d ", i);
    
    return 0;
}
#endif
