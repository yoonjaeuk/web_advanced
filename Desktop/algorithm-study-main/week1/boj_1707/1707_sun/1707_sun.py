from collections import deque
import sys


def bfs(start):
    Q = deque()
    Q.append((start, 0))  # start 노드 부터 시작, 0 을 칠해준다.
    flag = True
    visited[start] = 0

    while Q:
        node, type = Q.popleft()

        for next in graph[node]:
            if visited[next] == -1:  # 만일 방문 안한 노드 라면, 큐에 추가
                if type == 0:
                    new_type = 1
                else:
                    new_type = 0
                visited[next] = new_type
                Q.append((next, new_type))
            elif visited[next] == type:
                flag = False
                break
    return flag


if __name__ == "__main__":
    input = sys.stdin.readline
    T = int(input())

    for _ in range(T):
        V, E = map(int, input().split())
        graph = [[] for _ in range(V+1)]
        visited = [-1] * (V+1)
        
        for _ in range(E):
            s, e = map(int, input().split())
            graph[s].append(e)
            graph[e].append(s)

        answer = True
        for t in range(1, V+1):
            if visited[t] == -1:
                answer= bfs(t)
                if answer == False:
                    break
        if answer:
            print("YES")
        else:
            print("NO")
