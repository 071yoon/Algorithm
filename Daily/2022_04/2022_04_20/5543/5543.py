burger = 2000
drink = 2000
for i in range(0, 3):
	a = int(input())
	burger = min(a, burger)
for i in range(0, 2):
	a = int(input())
	drink = min(a, drink)
print(burger + drink - 50)