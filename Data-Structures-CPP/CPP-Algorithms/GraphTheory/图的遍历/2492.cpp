#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPath = INT_MAX;
    bool visited[1000000] = {false};
    void dfs(vector<vector<pair<int, int>>>& graph, int v){
        visited[v] = true;
        for(int i=0; i<graph[v].size(); i++){
            int w = graph[v][i].first, dis = graph[v][i].second;
            minPath = min(minPath, dis);
            if(!visited[w])
                dfs(graph, w);
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto road : roads){
            int x = road[0], y = road[1], dis = road[2];
            graph[x].push_back(pair<int, int>(y, dis));
            graph[y].push_back(pair<int, int>(x, dis));
        }
        dfs(graph, 1);
        return minPath;
    }
};