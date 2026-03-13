#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> g(n);
        //建图
        for(auto m:invocations){
            int x = m[0];
            int y = m[1];
            g[x].push_back(y);
        }
        //dfs
        vector<bool> vis(n,false);
        auto dfs = [&](this auto&& dfs,int cur)->void{
            vis[cur]=true;
            for(auto m : g[cur]){
                if(!vis[m]){
                    dfs(m);
                }
            }
        };
        
        dfs(k);

        auto it = find(vis.begin(),vis.end(),0);
        if(it==vis.end()){
            return {};
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(vis[i]){
                continue;
            }
            ans.push_back(i);
            for(auto x:g[i]){
                if(vis[x]){
                    vector<int> ans(n);
                    iota(ans.begin(),ans.end(),0);
                    return  ans;
                }
            }
        }

        return ans;

    }
};