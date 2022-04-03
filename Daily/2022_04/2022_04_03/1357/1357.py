a, b = map(str, input().split())
ret = str(int(a[::-1]) + int(b[::-1]))
print(int(ret[::-1]))