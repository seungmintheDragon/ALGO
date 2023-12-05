def moo(k, bef_len):  # k, S(k-1)의 길이
    global N
    now_len = bef_len * 2 + k + 3
    if N <= 3:
        a = ['m', 'o', 'o']
        print(a[N - 1])
        exit(0)
    if now_len < N:  # 왼쪽
        moo(k + 1, now_len)
    else:
        if bef_len < N <= k + bef_len + 3:  # 중간
            if N - bef_len == 1:
                print('m')
            else:
                print('o')
            exit(0)
        else:  # 오른쪽
            N -= k + bef_len + 3
            moo(1, 3)


N = int(input())
moo(1, 3)