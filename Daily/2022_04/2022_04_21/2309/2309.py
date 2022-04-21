from itertools import combinations
arr = []
sum = 0
for i in range(9):
	arr.append(int(input()))
	sum += arr[i]
arr.sort()
for a, b in combinations(arr, 2):
	if (sum - a - b == 100):
		for i in range(len(arr)):
			if (arr[i] != a and arr[i] != b):
				print(arr[i])
		break
