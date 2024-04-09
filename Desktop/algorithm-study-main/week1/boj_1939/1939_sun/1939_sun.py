import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())

Link = [[] for _ in range(N+1)]

# 입력 값 받기
for _ in range(M):
    s, e, w = map(int, input().split())
    Link[s].append((e, w))  # (도착도시, 중량) 순으로 저장
    Link[e].append((s, w)) 

def BFS(Weight):
    # BFS 알고리즘을 사용해서, 제한한 중량안에 End까지 도달 가능한지 판단하는 함수
    visited = [False] * (N+1)
    Queue = deque()
    Queue.append(Start) # 큐에는 도시를 저장한다.
    visited[Start] = True

    while Queue:
        now = Queue.popleft()
        if now == End:
            return True # 만일 도착한 경우, True 반환
        for next, weight in Link[now]:
            if (not visited[next]) and (weight >= Weight):
                Queue.append(next)
                visited[next] = True
    return False

Start, End = map(int, input().split())
low, high = 1, 1000000000

while low <= high:
    mid = (low + high) // 2
    if BFS(mid): # 만일 제한된 중량으로 도달 가능하면, 
        low = mid + 1
    else:
        high = mid -1

print(high)



