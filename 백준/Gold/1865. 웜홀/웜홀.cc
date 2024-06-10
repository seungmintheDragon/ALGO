#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

struct edge {
    int s, e, t;
};

int TC;
int n, m, w;
vector<edge> edges; 

bool bellmanford() {
    vector<int> dist(n + 1, INF);
    
    dist[1] = 0;
    
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < edges.size(); j ++) {
            int s = edges[j].s;
            int e = edges[j].e;
            int t = edges[j].t;
            
            if(dist[e] > dist[s] + t) dist[e] = dist[s] + t;
        }
    }
    
    for(int j = 0; j < edges.size(); j ++) {
        int s = edges[j].s;
        int e = edges[j].e;
        int t = edges[j].t;

        if(dist[e] > dist[s] + t) return true;
    }
    
    return false;
}


void solve() {
    cin >> n >> m >> w;
    int s,e,t;
    for(int i = 0; i < m; i ++) {
        cin >> s >> e >> t;
        edges.push_back({s, e, t});
        edges.push_back({e, s, t});
    }
    
    for(int i = 0; i < w; i ++) {
        cin >> s >> e >> t;
        edges.push_back({s, e, -t});
    }
    
    if(bellmanford()) cout << "YES\n";
    else cout << "NO\n";
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> TC;
    while(TC --) {
        edges.clear();
        solve();
    }
    return 0;
}