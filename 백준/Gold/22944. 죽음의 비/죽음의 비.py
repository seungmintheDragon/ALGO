from sys import stdin
N, H, D = map(int, stdin.readline().split())
area = [stdin.readline().rstrip() for _ in range(N)]
umbrella_position = []
direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def calc_distance(y1, x1, y2, x2):
    return abs(y1 - y2) + abs(x1 - x2)


def change_min_cnt(y, x, power, duration, cnt):
    global min_cnt
    if cnt >= min_cnt:
        return
    if y == end_y and x == end_x:
        min_cnt = cnt
        return
    for i in range(K):
        if not visited[i]:
            visited[i] = True
            new_distance = calc_distance(*umbrella_position[i], y, x)
            if new_distance <= duration:
                change_min_cnt(*umbrella_position[i], power, D, cnt + new_distance)
            else:
                np = power - new_distance + duration
                if np >= 0:
                    change_min_cnt(*umbrella_position[i], np, D, cnt + new_distance)
            visited[i] = False

for i in range(N):
    for j in range(N):
        dot = area[i][j]
        if dot == 'U':
            umbrella_position.append((i, j))
        elif dot == 'S':
            start_y, start_x = i, j
        elif dot == 'E':
            end_y, end_x = i, j
            umbrella_position.append((i, j))

shortest_distance = calc_distance(start_y, start_x, end_y, end_x)
K = len(umbrella_position)
visited = [False] * K
max_cnt = min_cnt = N * N * K + 10000000
umbrella_position.sort()
if shortest_distance >= H:
    change_min_cnt(start_y, start_x, H, 0, 0)
    if min_cnt != max_cnt:
        print(min_cnt)
    else:
        print(-1)
else:
    print(shortest_distance)