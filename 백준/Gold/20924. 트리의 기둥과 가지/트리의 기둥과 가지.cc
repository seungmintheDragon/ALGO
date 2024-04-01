#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, root;
int tree_size, branch_size;
int is_visited[200001];
vector<vector<pair<int, int>>> arr;


void Make_branch(int cur, int level) {
	if (is_visited[cur] == 1) return;
	is_visited[cur] = 1;
	int cnt = arr[cur].size();
	for (pair<int,int> n : arr[cur]) {
		cnt -= is_visited[n.first];
	}

	if (cnt == 0) {
		branch_size = max(branch_size, level);
		return;
	}

	for (pair<int, int> n : arr[cur]) {
		if (is_visited[n.first] == 1) continue;
		Make_branch(n.first, level + n.second);
	}
}

void Make_Tree(int cur, int level) {
	if (is_visited[cur] == 1) return;
	is_visited[cur] = 1;
	int cnt = arr[cur].size();
	for (pair<int, int> n : arr[cur]) {
		cnt -= is_visited[n.first];
	}

	if (cnt == 0) {
		tree_size = level;
		return;
	}

	if (cnt == 1) {
		for (pair<int, int> n : arr[cur]) {
			if (is_visited[n.first] == 1) continue;
			Make_Tree(n.first, level + n.second);
			return;
		}
		return;
	}

	for (pair<int, int> n : arr[cur]) {
		if (is_visited[n.first] == 1) continue;
		tree_size = level;
		Make_branch(n.first, n.second);
	}
}




void Input() {
	cin >> n >> root;
	arr.assign(n + 1, {});
	int a, b, d;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> d;
		arr[b].push_back({a, d});
		arr[a].push_back({b, d});

	}
	Make_Tree(root, 0);
}




int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Input();
	cout << tree_size << " " << branch_size;
	return 0;
}