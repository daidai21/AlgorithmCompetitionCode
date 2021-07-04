def perm(n):
    dot = 1
    for i in range(1, n + 1):
        dot *= i
    return dot


if __name__ == "__main__":
    while True:
        try:
            [n, m] = list(map(int, input().split()))
            res = perm(m + n) / (perm(m) * perm(n))
            print(int(res))
        except:
            break
