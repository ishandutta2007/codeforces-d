print((lambda n, k: ["NO", "YES"][n // k % 2])(*map(int, input().split())))