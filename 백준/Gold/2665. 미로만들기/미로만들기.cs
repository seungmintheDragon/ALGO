int n = int.Parse(Console.ReadLine());
char[,] room = new char[55, 55];
int[] dx = { 1, -1, 0, 0 };
int[] dy = { 0, 0, 1, -1 };
int[,] roomcounting = new int[55,55];

for (int i = 0; i < n; i++)
{
    string inputroom = Console.ReadLine();
    for (int j = 0; j < n; j++)
        room[i, j] = inputroom[j];
}
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {
        roomcounting[i, j] = int.MaxValue / 2;
    }
}

Queue<(int,int)> q = new Queue<(int, int)>();
q.Enqueue((0, 0));
roomcounting[0, 0] = 0;
while (q.Count != 0)
{
    (int, int) cur = q.Dequeue();
    for (int i = 0; i < 4; i++)
    {
        int nx = cur.Item1 + dx[i];
        int ny = cur.Item2 + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (roomcounting[nx, ny] <= roomcounting[cur.Item1, cur.Item2])
            continue;

        if (room[nx, ny] == '0')
        {
            if (roomcounting[nx, ny] == roomcounting[cur.Item1, cur.Item2] + 1)
                continue;
            roomcounting[nx, ny] = roomcounting[cur.Item1, cur.Item2] + 1;
        }
        else
            roomcounting[nx, ny] = roomcounting[cur.Item1, cur.Item2];
        q.Enqueue((nx, ny));
    }
}

Console.WriteLine(roomcounting[n - 1, n - 1]);
