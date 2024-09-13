while True:
    D, N = map(str, input().split())
    if D == '0' and N == '0':
        break
    N = N.replace(D, "")
    if N == '':
        N = '0'
    print(int(N))
