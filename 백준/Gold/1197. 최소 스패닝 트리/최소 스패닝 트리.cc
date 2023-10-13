#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
vector <pair<int, pair<int, int>>> nodes;
int V, E;
long long result = 0;

int find_Parent(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = find_Parent(parent[x]);
}

void union_Parent(int x, int y)
{
    x = find_Parent(x);
    y = find_Parent(y);
    parent[y] = x;
}

bool same_Parent(int x, int y)
{
    x = find_Parent(x);
    y = find_Parent(y);
    if (x == y) return true;
    else return false;
}

void input()
{
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        nodes.push_back({ C, {A , B} });
    }
    sort(nodes.begin(), nodes.end());
}

void kruskal()
{
    for (int i = 0; i < nodes.size(); i++)
    {
        if (!same_Parent(nodes[i].second.first, nodes[i].second.second))
        {
            union_Parent(nodes[i].second.first, nodes[i].second.second);
            result += nodes[i].first;
        }
    }

    cout << result << '\n';
}


int main()
{
    input();
    kruskal();
    return 0;
}
