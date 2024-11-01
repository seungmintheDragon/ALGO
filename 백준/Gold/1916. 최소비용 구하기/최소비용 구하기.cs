class Program
{
    static void Main(string[] args)
    {
        const int INF = int.MaxValue / 2;
        int N = int.Parse(Console.ReadLine());  // 도시의 개수
        int M = int.Parse(Console.ReadLine());  // 버스의 개수

        // 인접 행렬 초기화
        int[,] graph = new int[N + 1, N + 1];
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i != j) graph[i, j] = INF;
            }
        }

        // 간선 입력
        for (int i = 0; i < M; i++)
        {
            int[] busInfo = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int from = busInfo[0];
            int to = busInfo[1];
            int cost = busInfo[2];
            graph[from, to] = Math.Min(graph[from, to], cost);
        }

        int[] input = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int start = input[0];
        int end = input[1];

        // 다익스트라
        int[] minDist = new int[N + 1];     // 시작 노드에서 각 정점까지의 최단 경로
        bool[] visited = new bool[N + 1];   // 방문 여부 체크(가까운 노드부터 방문)
        for(int i = 1; i <= N; i++)
        {
            minDist[i] = INF;
        }
        minDist[start] = 0; // 시작 노드에서 시작 노드로 가는 거리는 0

        for (int i = 1; i <= N; i++)
        {
            int u = -1; // 현재까지 처리한 노드 중에서 최단 거리에 해당하는 노드 저장
            for (int j = 1; j <= N; j++)
            {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                {
                    u = j; // 방문하지 않은 노드 중 가장 가까운 노드를 u에 저장
                }
            }

            if (minDist[u] == INF) break;   // 접근 가능한 노드가 없다면 break

            visited[u] = true;

            // 현재 노드 u에서 접근 가능한 다른 노드 순회
            for (int v = 1; v <= N; v++)
            {
                if (!visited[v] && graph[u, v] < INF)
                {
                    minDist[v] = Math.Min(minDist[v], minDist[u] + graph[u, v]);
                }
            }
        }

        Console.WriteLine(minDist[end]);
    }
}