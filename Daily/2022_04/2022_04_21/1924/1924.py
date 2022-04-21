day = 0
month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
week = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']

mon, wee = map(int, input().split())

for i in range(mon - 1):
	day = day + month[i]
day = (day + wee) % 7
print(week[day])