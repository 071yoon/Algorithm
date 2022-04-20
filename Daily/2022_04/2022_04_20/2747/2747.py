dp = [0, 1]
for i in range(2, 46):
	dp.append(dp[i - 1] + dp[i - 2])
cnt = int(input())
print(dp[cnt])