#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Child_Node
{
	int node, depth;
};

vector<vector<Child_Node>> graph;
int n, root;
int tree_size, branch_size;
int is_visited[200001];
vector<vector<Child_Node>> arr;


void Make_Tree(int cur) {
	if (is_visited[cur] == 1) return;
	is_visited[cur] = 1;
	//cout << arr[cur].size() << "\n";

	for (Child_Node n : arr[cur]) {
		//cout << n.node << "\n";
		//cout << n.depth << "\n";
		if (is_visited[n.node] == 1) continue;
		graph[cur].emplace_back(n);
		Make_Tree(n.node);
	}
}



void Input() {
	cin >> n >> root;
	graph.assign(n + 1, {});
	arr.assign(n + 1, {});
	int a, b, d;
	Child_Node temp_node;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> d;
		temp_node.node = a;
		temp_node.depth = d;
		//cout << temp_node.node;
		arr[b].emplace_back(temp_node);
		temp_node.node = b;
		//cout << temp_node.node;
		arr[a].emplace_back(temp_node);

	}
	Make_Tree(root);
}


void DFS_Branch(int cur, int bracn_level) {
	if (graph[cur].size() == 0) {
		branch_size = max(bracn_level, branch_size);
		return;
	}
	for (Child_Node next_node : graph[cur])
	{
		DFS_Branch(next_node.node, bracn_level + next_node.depth);
	}
}

void DFS(int cur, int tree_level) {
	if (graph[cur].size() == 1) 
	{
		DFS(graph[cur][0].node, tree_level + graph[cur][0].depth);
		return;
	}

	tree_size = tree_level;
	if (graph[cur].size() == 0) return;
	for (Child_Node next_node : graph[cur])
	{
		DFS_Branch(next_node.node, next_node.depth);
	}
}



int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Input();
	DFS(root, 0);
	cout << tree_size << " " << branch_size;
	return 0;
}