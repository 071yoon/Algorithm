'''
0 -> 4
1 -> 3 ~ 5
2 -> 2 ~ 6
3 -> 1 ~ 7
4 -> 0 ~ 8
'''
cnt = int(input())
for i in range(cnt):
	start = cnt - 1 - i
	end = cnt - 1 + i
	str = ""
	for j in range(end + 1):
		if (j >= start and j <= end):
			str += "*"
		else:
			str += " "
	print(str)
		