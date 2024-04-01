#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Child_Node
{
	int node, depth;
};

int n, root;
int tree_size, branch_size;
int is_visited[200001];
vector<vector<Child_Node>> arr;


void Make_branch(int cur, int level) {
	if (is_visited[cur] == 1) return;
	is_visited[cur] = 1;
	int cnt = arr[cur].size();
	for (Child_Node n : arr[cur]) {
		cnt -= is_visited[n.node];
	}

	if (cnt == 0) {
		branch_size = max(branch_size, level);
		return;
	}

	for (Child_Node n : arr[cur]) {
		if (is_visited[n.node] == 1) continue;
		Make_branch(n.node, level + n.depth);
	}
}

void Make_Tree(int cur, int level) {
	if (is_visited[cur] == 1) return;
	is_visited[cur] = 1;
	int cnt = arr[cur].size();
	for (Child_Node n : arr[cur]) {
		cnt -= is_visited[n.node];
	}

	if (cnt == 0) {
		tree_size = level;
		return;
	}

	if (cnt == 1) {
		for (Child_Node n : arr[cur]) {
			if (is_visited[n.node] == 1) continue;
			Make_Tree(n.node, level + n.depth);
			return;
		}
		return;
	}

	for (Child_Node n : arr[cur]) {
		if (is_visited[n.node] == 1) continue;
		tree_size = level;
		Make_branch(n.node, n.depth);
	}
}




void Input() {
	cin >> n >> root;
	arr.assign(n + 1, {});
	int a, b, d;
	Child_Node temp_node;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> d;
		temp_node.node = a;
		temp_node.depth = d;
		arr[b].emplace_back(temp_node);
		temp_node.node = b;
		arr[a].emplace_back(temp_node);

	}
	Make_Tree(root, 0);
}




int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Input();
	cout << tree_size << " " << branch_size;
	return 0;
}