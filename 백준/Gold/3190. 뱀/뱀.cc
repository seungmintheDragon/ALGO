#include <iostream>
#include <queue>

using namespace std;

int n, k, l;
int arr[101][101];
int visited[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool in_Range(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    cin >> l;
    queue<pair<int, int>> q;
    int dir = 0;
    int x = 1;
    int y = 1;
    int cnt = 0;
    q.push(make_pair(x, y));
    for (int i = 0; i < l; i++) {
        int k;
        char c;
        cin >> k >> c;
        while (cnt < k || i == l - 1) {
            cnt++;
            
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            //cout << x << " " << y << "new :" << nx  << " " << ny << "\n";
            if (in_Range(nx, ny) && !visited[nx][ny]) {
                
                if (arr[nx][ny] == 1) {
                    arr[nx][ny] = 0;
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                }
                else {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    visited[q.front().first][q.front().second] = 0;
                    q.pop();
                }
            }
            else {
                cout << cnt;
                return 0;
            }
            x = nx;
            y = ny;
            
            if (cnt == k) {
                if (c == 'D') dir = (dir + 1) % 4;
                else dir = (dir + 3) % 4;
            }
        }
    }

    return 0;
}