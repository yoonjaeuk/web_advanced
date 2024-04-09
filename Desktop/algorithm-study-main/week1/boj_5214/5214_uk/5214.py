import sys
input = sys.stdin.readline
from collections import deque
sys.setrecursionlimit(10000000)
#최단거리, 최소한의 개수 이런게 나오면 bfs가 적절한듯 bfs가 알아서 최소거리 구함
#하이퍼튜브를 이용해서 역을 찾아나가야 됨

def bfs(end_point, station, hyper_tube):
  start_point = 1 #start_point가 end_point에 도착했을때 종료
  visited = [False] * (N+1) #노드(point) = station 방문
  visited_hyper = [False] * (M) #hyper_tube 방문
  dq = deque()
  dq.append((start_point, 1)) #now_point, count
  while dq:
    now, cnt = dq.popleft()
    next_hyper = []
    for hyper_idx in station[now]: #역 
      if not visited_hyper[hyper_idx]: #역 -> 하이퍼튜브
         visited_hyper[hyper_idx] = True
         next_hyper.append(hyper_idx)
    for hyper in next_hyper: #하이퍼튜브
      for state in hyper_tube[hyper]: #하이퍼튜브 -> 역
        if not visited[state]:
           if state == end_point:
              return cnt + 1
           visited[state] = True
           dq.append((state, cnt+1))
           
  
  return -1


if __name__ == "__main__":
  #print("입력하세요")                     
  N, k, M = map(int, input().split())
  end_point = N
  stations = [[]for _ in range(N+1)] #각 역별로 탑승가능한 하이퍼튜브
  hyper_tubes = [[]for _ in range(M)] #하이퍼튜브
  for i in range(M):
    X = list(map(int, input().split())) #input하고 싶은게 얼마나 되는지 모를때는 list형태로 input을 받는다
    for num in X:
      stations[num].append(i)
      hyper_tubes[i].append(num)
  if N==1:
     print(1)
  #print(stations)
  #print(hyper_tubes)  
  else:    
     count = bfs(end_point, stations, hyper_tubes)
     print(count)