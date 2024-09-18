n = int(input())
stair = [0]
for _ in range(n):
    stair.append(int(input()))

dp = [0] * (n + 1)
dp[1] = stair[1]
if n == 1:
    print(dp[1])
    exit()

dp[2] = stair[1] + stair[2]
if n == 2:
    print(dp[2])
    exit()


for i in range(3, n):
    dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], 
                stair[i] + dp[i-2], 
                stair[i -1])
print(max(stair[n] + dp[n - 2], stair[n] + stair[n - 1] + dp[n - 3]))