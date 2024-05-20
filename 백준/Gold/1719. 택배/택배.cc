#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 987654321
 
using namespace std;
 
int n, m, dis, pos, ndis, npos; // n = 1번부터 n번까지 집하장 개수
vector<pair<int, int>> map[201];
int ans[201][201];
int stp[201][201];
 
 
void delivery(int from) {
    for (int i = 1; i <= n; i++) ans[from][i] = MAX, stp[from][i] = MAX;
    ans[from][from] = 0;
    stp[from][from] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,from });
    while (!pq.empty()) {
        dis = pq.top().first; // first 는 누적 거리
        pos = pq.top().second; // second는 현 위치
        pq.pop(); 
        for (int i = 0; i < map[pos].size(); i++) {
            npos = map[pos][i].first;
            ndis = map[pos][i].second;
            if (ans[from][npos] > ans[from][pos] + ndis) {
                ans[from][npos] = ans[from][pos] + ndis;
                if(stp[from][pos]==0) stp[from][npos] = npos;
                else stp[from][npos] = stp[from][pos];
                pq.push({ ans[from][npos],npos });
            }
        }
    }
}
 
void input() {
    int to, from, dis;
    cin >> n >> m;
    while (m--) {
        cin >> to >> from >> dis;
        map[to].push_back({ from,dis });
        map[from].push_back({ to,dis });
    }
}
 
void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) cout << "-" << " ";
            else cout << stp[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    input();
    for (int i = 1; i <= n; i++) delivery(i);
    output();
    return 0;
}