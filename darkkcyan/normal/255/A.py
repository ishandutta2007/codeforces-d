print((lambda n, a: max((sum(a[0::3]), "chest"), (sum(a[1::3]), "biceps"), (sum(a[2::3]), "back"))[1])(int(input()), list(map(int, input().split()))))