#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
	int left, right;
};

int n, ans_width, ans_level;
int nums = 1;
vector<Node> graph;
int is_visited[10001];
vector<vector<int>> arr;


void Input() {
	cin >> n;
	graph.assign(n + 1, {});
	for (int i = 1; i <= n; i++)
	{
		int a, l, r;
		cin >> a >> l >> r;
		graph[a] = { l , r };
		if (l != -1) is_visited[l] ++;
		if (r != -1) is_visited[r] ++;
	}
}

// 중위순회(현재 위치, 레벨{깊이})
void InOrder(int cur, int level) {
	if (cur == -1) return;

	InOrder(graph[cur].left, level + 1);

	if (arr.size() <= level) arr.resize(level + 1);
	arr[level].emplace_back(nums++);

	InOrder(graph[cur].right, level + 1);
}

void Find_ans() {
	int temp = 0;
	for (int i = 1; i < arr.size(); i++) {
		sort(arr[i].begin(), arr[i].end());
		temp = arr[i][arr[i].size() - 1] - arr[i][0] + 1;

		if (temp > ans_width) {
			ans_level = i;
			ans_width = temp;
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Input();
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (is_visited[i] == 0) {
			root = i;
			break;
		}
	}
	InOrder(root, 1);
	Find_ans();

	cout << ans_level << " " << ans_width << "\n";
	return 0;
}

