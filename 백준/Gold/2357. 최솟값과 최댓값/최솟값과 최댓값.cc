#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100001

using namespace std;

int arr[MAX];
vector<int> min_tree, max_tree;
int n, m;

void init(int node, int start, int end) {
    if (start == end) {
        min_tree[node] = max_tree[node] = arr[start];
        return;
    }

    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
    max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
}

pair<int, int> find_seg(int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return { INT32_MAX, 0 };
    }
    else if (left <= start && end <= right) {
        return { min_tree[node], max_tree[node] };
    }
    else {
        pair<int, int> l, r;
        l = find_seg(node * 2, start, (start + end) / 2, left, right);
        r = find_seg(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return { min(l.first, r.first), max(l.second, r.second) };
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int h = (int)ceil(log2(n));
    min_tree = vector<int>(1 << (h + 1));
    max_tree = vector<int>(1 << (h + 1));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);
    pair<int, int> ans;
    int left, right;

    while (m--) {
        cin >> left >> right;
        ans = find_seg(1, 1, n, left, right);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}