#include<iostream>
#include<vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int>train(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b;
        if (a <= 2) cin >> c;

        if (a == 1) {
            train[b] |= (1 << c);
        }
        else if (a == 2) {
            train[b] &= ~(1 << c);
        }
        else if (a == 3) {
            train[b] = train[b] << 1;
            train[b] &= ((1 << 21) - 1);
        }
        else if (a == 4) {
            train[b] = train[b] >> 1;
            train[b] &= ~1;
        }
    }

    vector<bool>visited(1 << 21, false);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[train[i]]) {
            ans++;
            visited[train[i]] = true;
        }
    }
    cout << ans << endl;

    return 0;
}