import sys
input = sys.stdin.readline

N, C = map(int, input().split())

Houses = []

for _ in range(N):
    Houses.append(int(input()))

Houses.sort()

start, end = 1, (Houses[-1]-Houses[0])  # 최소 거리와 최대 거리(가장 멀리 떨어진 집)

answer = 0

while start <= end:
    mid = (start + end) // 2
    cnt = 1
    cur = Houses[0] # 현재 집의 위치

    # 두번째 집부터 탐색
    for i in range(1, N):
        if Houses[i] - cur >= mid:    # 설치예정인 집이 마지막으로 설치한 곳과의 거리보다 크면 설치
            cnt += 1
            cur = Houses[i] # 마지막 설치위치 기록

    # 만약 총 설치개수가 C보다 크면
    if cnt >= C:
        answer = mid # 일단 기록 
        start = mid + 1 # 간격을 늘림
    else:   # C보다 작으면
        end = mid - 1 # 간격을 줄임 

print(answer)