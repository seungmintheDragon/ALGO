#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int A[10][10], result = 1e9;
int paper[6];

bool checkSquare(int y, int x, int size) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (!A[i][j]) return false;
        }
    }
    return true;
}

void changeMap(int y, int x, int size, int tf) {
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            A[i][j] = tf;
        }
    }
}

void dfs(int y, int x, int count) {
    while (!A[y][x]) {
        x++;
        if (x >= 10) {
            y++;
            if (y >= 10) {
                result = min(result, count);
                return;
            }
            x = 0;
        }
    }

    if (result <= count) return;

    for (int i = 5; i >= 1; i--) {
        if (y + i > 10 || x + i > 10) continue;
        if (paper[i] == 5) continue;
        if (!checkSquare(y, x, i)) continue;

        paper[i]++;
        changeMap(y, x, i, 0);
        dfs(y, x, count + 1);
        paper[i]--;
        changeMap(y, x, i, 1);
    }
}

void solution() {
    dfs(0, 0, 0);

    if (result == 1e9) result = -1;
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }

    solution();

    return 0;
}