A, B = map(int, input().split())

flag = 1
while A < B:
    if str(B)[-1] == "1":  # 끝자리가 1인 경우
        flag += 1
        B = int(str(B)[:-1])
    elif B % 2 == 0:  # 2로 나눠 떨어지는 경우
        flag += 1
        B = B // 2
    else:
        flag = -1
        break

if flag == -1 or A != B:
    print(-1)
else:
    print(flag)
