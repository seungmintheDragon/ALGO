from collections import deque


def dugs(a, b, arr):
    di = [0, 0, -1, 1]
    dj = [1, -1, 0, 0]
    global cnt
    global n
    global m
    queue = deque()
    queue.append((a, b))

    while queue:
        left, right = queue.popleft()
        for i in range(4):
            ni = left + di[i]
            nj = right + dj[i]
            if 0 <= ni < n and 0 <= nj < m and arr[ni][nj] == 1:
                queue.append((ni, nj))
                arr[ni][nj] = 0

t = int(input())

for tc in range(t):
    n, m, k = map(int, input().split())
    arr = list([0] * m for _ in range(n))
    for __ in range(k):
        a, b = map(int, input().split())
        arr[a][b] = 1

    cnt = 0

    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1:
                arr[i][j] = 0
                dugs(i,j ,arr)
                cnt += 1
    print(cnt)