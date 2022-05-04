cnt = int(input())

for i in range(cnt - 1):
	for j in range(i):
		print(' ', end='')
	for j in range(cnt * 2 - 2 * i - 1):
		print('*', end='')
	print('')
for i in range(cnt - 1):
	print(' ', end='')
print('*')
for i in range(cnt - 1):
	for j in range(cnt - i - 2):
		print(' ', end='')
	for j in range(i * 2 + 3):
		print('*', end='')
	print('')



