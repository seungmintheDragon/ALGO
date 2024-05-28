#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;
int n;
int answer = 987654321;
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

bool in_Range(int x , int y) {
    return 0 <= x && x < n && 0<=y && y < n;
}

void DFS(int x, int y, int cost, int dir , vector<vector<int>> &board) {
    if (cost > answer) {
        return;
    }
    
    if(x == n - 1 && y == n - 1) {
        return;
    }
    
    for(int d = 0; d < 4; d ++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        int ncost = (dir == d) ? cost + 100 : cost + 600;
        if(in_Range(nx, ny) && board[nx][ny] == 0 && v[nx][ny] >= ncost) {
            v[nx][ny] = ncost;
            DFS(nx, ny, ncost, d, board);
        }
    }
}



int solution(vector<vector<int>> board) {
    n = board.size();
    v.resize(n, vector<int>(n, 987654321));
    for(int d = 0; d < 4; d ++) {
        DFS(0, 0, 0, d, board);
    }
    
    // for(int i = 0; i < n; i ++) {
    //     for(int j = 0; j < n; j ++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    return v[n-1][n-1];
}