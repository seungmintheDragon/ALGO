#include <iostream>
#include <vector>

using namespace std;

vector<bool> hasP(10003, false); //해당 노드가 부모를 갖는지 판단
int rc[10003]; //우측 노드
int lc[10003]; //좌측 노드
int n, root;
int idx = 1; //각 노드는 중위순회를 했을 때 idx번째 탐색에 방문한다
int mxdepth;

int ans, level;
bool isAnswerRoot = true;
int mx[10003]; //해당 level에서의 최댓값
int mn[10003]; //해당 level에서의 최솟값

void DFS(int cur, int depth) {
    if (lc[cur]) DFS(lc[cur], depth + 1);
    //중위순회
    mxdepth = max(mxdepth, depth);
    mn[depth] = min(mn[depth], idx);
    mx[depth] = max(mx[depth], idx);
    idx ++;
    if (rc[cur]) DFS(rc[cur], depth + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    fill(mn, mn + 10003, 0x7f7f7f7f);
    for (int i = 0; i < n; i++) {
        int cur, l, r; cin >> cur >> l >> r;
        if (l != -1) { lc[cur] = l; hasP[l] = 1; }
        if (r != -1) { rc[cur] = r; hasP[r] = 1; }
    }
    for (int i = 1; i <= n; i++) { if (hasP[i] == 0) { root = i; break; } }
    DFS(root, 1);
    for (int i = 1; i <= mxdepth; i++) {
        if (mx[i] - mn[i] + 1 > ans) {
            if (i >= 2) isAnswerRoot = false;
            ans = mx[i] - mn[i] + 1;
            level = i;
        }
    }
    if (isAnswerRoot) {
        level = 1; ans = 1;
    }
    cout << level << ' ' << ans;
    return 0;
}