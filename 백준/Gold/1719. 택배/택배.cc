#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int n, m, dis, pos, ndis, npos;
vector<pair<int, int>> map[201];
int ans[201][201];
int tmp[201][201];

void dijkstra(int from) {
    for (int i = 1; i <= n; i++) {
        ans[from][i] = INF;
        tmp[from][i] = INF;
    }
    ans[from][from] = 0;
    tmp[from][from] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, from });
    while (!pq.empty()) {
        dis = pq.top().first;
        pos = pq.top().second;
        pq.pop();
        for (int i = 0; i < map[pos].size(); i++) {
            npos = map[pos][i].first;
            ndis = map[pos][i].second;
            if (ans[from][npos] > ans[from][pos] + ndis) {
                ans[from][npos] = ans[from][pos] + ndis;
                if (tmp[from][pos] == 0) tmp[from][npos] = npos;
                else tmp[from][npos] = tmp[from][pos];

                pq.push({ ans[from][npos], npos });
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int to, from, dis;
        cin >> to >> from >> dis;
        map[to].push_back({ from, dis });
        map[from].push_back({ to, dis });
    }

    for (int i = 1; i <= n; i++) dijkstra(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "- ";
            else cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}