#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> graph;
vector<bool> isVisited;
vector<int> generator;

void Input() {
    cin >> n >> m >> k;
    graph.assign(n + 1, vector<pair<int, int>>{});
    isVisited.assign(n + 1, false);
    generator.assign(k, 0);
    
    for(int i = 0; i < k; i ++) {
        cin >> generator[i];
    }
    
    for(int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
}

void setpq(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>& pq) {
    for(int i = 0; i < k; i ++) {
        isVisited[generator[i]] = true;
        for(int j = 0; j < graph[generator[i]].size(); j ++) {
            pq.push({graph[generator[i]][j].second, graph[generator[i]][j].first});
        }
    }
}

void prim() {
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    setpq(pq);
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(!isVisited[cur]) {
            isVisited[cur] = true;
            sum += cost;
            
            for(int i = 0; i < graph[cur].size(); i ++) {
                int next = graph[cur][i].first;
                int n_cost = graph[cur][i].second;
                
                if(!isVisited[next]) {
                    pq.push({n_cost, next});
                }
            }
        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Input();
    prim();
    
    
    return 0;
}