cnt = int(input())
for i in range(cnt):
	for j in range(i):
		print(' ', end='')
	for k in range(cnt - i):
		print('*', end='')
	print('')