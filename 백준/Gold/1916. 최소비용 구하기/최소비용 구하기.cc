#include <iostream>
#include <queue>
#define INF 10e9

using namespace std;

int N, M;
vector<pair<int, int>> nodes[1001];
int S, E;
int dist[1001];

void input()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		nodes[a].push_back({ b,c });
	}
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	cin >> S >> E;
}

void Dijkstra()
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, S });
	dist[S] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (dist[current] < cost) continue;

		for (pair<int, int> node : nodes[current])
		{
			int next = node.first;
			int next_cost = node.second;

			if (dist[next] > cost + next_cost)
			{
				dist[next] = cost + next_cost;
				pq.push({ -dist[next], next });
			}
		}
	}

}

int main()
{
	input();
	Dijkstra();
	cout << dist[E] << endl;
	return 0;
}