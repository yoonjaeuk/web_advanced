from collections import deque

N, M = map(int, input().split())
# 그래프 기록
graph = [[] for _ in range(N+1)]

for i in range(N-1):
    s, e, w = map(int, input().split())
    graph[s].append((e, w))
    graph[e].append((s, w))

def bfs(start, end):
    Q = deque()
    Q.append((start, 0))
    while Q:
        now, weight = Q.popleft()
        if now == end:
            return weight
        visited[now]=True
        for next, w in graph[now]:
            if not visited[next]:
                distance = weight + w
                Q.append((next, distance))


for t in range(M):
    visited = [False] * (N+1)
    Start, End = map(int, input().split())
    print(bfs(Start, End))
