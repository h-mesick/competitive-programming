#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

unordered_map<int, queue<int>> last;
int bit[MM];

void update(int i, int v){
    for(i++; i < MM; i += i&-i)
        bit[i] += v;
}

int query(int i){
    int ret = 0;
    for(i++; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

long long count_swaps(vector<int> vec){
    long long ans = 0;
    for(int i = 0; i < vec.size(); i++){
        if(!last[-vec[i]].empty()){
            int rm = last[-vec[i]].front();
            last[-vec[i]].pop();
            ans += (vec[rm]>0) + query(i) - query(rm);
            update(rm, 1);
        }
        else{
            update(i, 1);
            last[vec[i]].push(i);
        }
    }
    return ans;
}

#ifndef ONLINE_JUDGE
int main(){
    
    print(count_swaps({2, 1, -1, -2}));
    print(count_swaps({-2, 2, 2, -2, -2, 2}));
    
    return 0;
}
#endif
