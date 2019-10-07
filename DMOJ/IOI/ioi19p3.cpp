#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
const int MM = 2502;

int n, m, ans, stl, vecl;
int first[MM], last[MM], bit[MM];
std::pair<int, int> st[MM], vec[MM];
std::vector<std::pair<int, int>> hor[MM][MM], vert[MM][MM];

inline void update(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}

inline int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

long long count_rectangles(std::vector<std::vector<int>> a){
    n = a.size(), m = a[0].size();
    
    for(int i = 0; i < n; i++){
        stl = 0;
        for(int j = 0; j < m; j++){
            //remove duplicates
            while(stl && st[stl].first < a[i][j])
                stl--;
            first[j] = (!stl || st[stl].first == a[i][j]) ? -1 : st[stl].second;
            st[++stl] = {a[i][j], j};
        }
        stl = 0;
        for(int j = m-1; j >= 0; j--){
            while(stl && st[stl].first <= a[i][j])
                stl--;
            last[j] = !stl ? -1 : st[stl].second;
            st[++stl] = {a[i][j], j};
        }
        for(int j = 0; j < m; j++){
            if(first[j] == -1 || last[j] == -1)
                continue;
            
            first[j]++, last[j]--;
            
            hor[i][first[j]].push_back({last[j], 1});
        }
    }
    
    for(int j = 0; j < m; j++){
        stl = 0;
        for(int i = 0; i < n; i++){
            //remove duplicates
            while(stl && st[stl].first < a[i][j])
                stl--;
            first[i] = (!stl || st[stl].first == a[i][j]) ? -1 : st[stl].second;
            st[++stl] = {a[i][j], i};
        }
        stl = 0;
        for(int i = n-1; i >= 0; i--){
            while(stl && st[stl].first <= a[i][j])
                stl--;
            last[i] = !stl ? -1 : st[stl].second;
            st[++stl] = {a[i][j], i};
        }
        for(int i = 0; i < n; i++){
            if(first[i] == -1 || last[i] == -1)
                continue;
            
            first[i]++, last[i]--;
            
            vert[first[i]][j].push_back({last[i], 1});
        }
    }
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            
            //assert(std::is_sorted(hor[i][j].begin(), hor[i][j].end()));
            //assert(std::is_sorted(vert[i][j].begin(), vert[i][j].end()));
            
            int l = 0, r = 0;
            
            while(l < vert[i][j].size() && r < vert[i][j+1].size()){
                if(vert[i][j][l].first == vert[i][j+1][r].first){
                    vert[i][j][l].second = vert[i][j+1][r].second+1;
                    l++;
                }
                else if(vert[i][j][l].first > vert[i][j+1][r].first)
                    r++;
                else
                    l++;
            }
            
            l = r = 0;
    
            while(l < hor[i][j].size() && r < hor[i+1][j].size()){
                if(hor[i][j][l].first == hor[i+1][j][r].first){
                    hor[i][j][l].second = hor[i+1][j][r].second+1;
                    l++;
                }
                else if(hor[i][j][l].first > hor[i+1][j][r].first)
                    r++;
                else
                    l++;
            }
    
            for(int k = 0; k < hor[i][j].size(); k++)
                vec[k] = hor[i][j][k];
            vecl = hor[i][j].size();
            
            sort(vec, vec+vecl, [](const std::pair<int, int> &x, const std::pair<int, int> &y){
                return x.second > y.second;
            });
            
            l = 0;
            
            for(int k = vert[i][j].size()-1; k >= 0; k--){
                auto &b = vert[i][j][k];
                while(l < vecl && b.first-i+1 <= vec[l].second){
                    update(vec[l++].first-j+1, 1);
                }
                ans += query(b.second);
            }
            
            while(l)
                update(vec[--l].first-j+1, -1);
        }
    }
    
    return ans;
}

#ifndef ONLINE_JUDGE
int main(){
    
    printf("%lld\n", count_rectangles({{4, 8, 7, 5, 6},
    {7, 4, 10, 3, 5},
    {9, 7, 20, 14, 2},
    {9, 14, 7, 3, 6},
    {5, 7, 5, 2, 7},
    {4, 5, 13, 5, 6}})
    );
    
    return 0;
}
#endif
