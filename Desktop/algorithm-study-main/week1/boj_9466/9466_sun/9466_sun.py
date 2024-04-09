from collections import deque
import sys
input = sys.stdin.readline
M = int(input())

def dfs(target):
    Q = deque()
    visited = [False] * (N+1)
    node = graph[target]
    if not visited[node]:
        Q.append(node)
    path = []

    while Q:
        now = Q.pop()
        visited[now] = True
        path.append(now)
        if now == target:
            return path
        next = graph[now]
        if not visited[next]:
            Q.append(next)
    
    return []

    
for _ in range(M):
    N = int(input())
    graph = [0] + list(map(int, input().split()))
    result = []
    for t in range(1, N+1):
        if t in result:
            continue
        result += dfs(t)

    print(N - len(result))
