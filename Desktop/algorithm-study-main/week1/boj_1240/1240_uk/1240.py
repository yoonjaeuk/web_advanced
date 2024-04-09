import sys
from collections import deque
input = sys.stdin.readline

def bfs(k_start, k_end):
  dq = deque()
  dq.append((k_start, 0))
  visited = [False] * (N+1)
  visited[k_start] = True
  while dq:
    cur, distance = dq.popleft()
    if cur == k_end:
      return distance
    for nei, dis in MAP[cur]:
        if visited[nei] == False:
          visited[nei] = True
          dq.append((nei, distance + dis))


if __name__ == "__main__":                     
  #print("입력하세요")
  N, M = map(int, input().split()) #첫째 줄 노드의 개수 N, 노드 쌍의 개수 M
  MAP = [[] * (N+1) for _ in range(N+1)]
  answer = []

  for i in range(N-1):
    start, end, dist = map(int, input().split())
    MAP[start].append((end, dist))
    MAP[end].append((start, dist)) 
 

  for j in range(M):
    k_start, k_end = map(int, input().split())
    answer.append(bfs(k_start, k_end))
  
  #print(MAP) 
  
  for k in answer:
    print(k)


