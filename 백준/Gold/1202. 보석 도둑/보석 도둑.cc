#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 300001
using namespace std;
int n, k;
int jewel_bag[MAX];
pair<int, int> jewely[MAX];
priority_queue<int, vector<int>, less<int>> pq;

long long solve() {
    sort(jewel_bag, jewel_bag + k);
    sort(jewely, jewely + n);
    int idx = 0;
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        while (idx < n && jewel_bag[i] >= jewely[idx].first) {
            pq.push(jewely[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    return sum;

}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> jewely[i].first >> jewely[i].second;
    }

    for (int i = 0; i < k; i++) {
        cin >> jewel_bag[i];
    }
    cout << solve();
    return 0;
}

