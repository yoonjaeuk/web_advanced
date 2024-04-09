import sys

input = sys.stdin.readline
N, M = map(int, input().split())
times = []

for _ in range(N):
    input_time = int(input())
    times.append(input_time)
times.sort()

def check_time(t):
    """
    주어진 시간 (t) 동안 입국 심사를 볼 수 있는 사람 수를 반환
    """
    total = 0
    for time in times:
        p_num = t // time
        total += p_num
    return total


low = 0
high = times[0] * M
answer = 0
while low <= high:
    mid = (low + high) // 2
    p_num = check_time(mid)
    if p_num >= M:
        high = mid - 1
    else:
        low = mid + 1
        answer = low

print(answer)
