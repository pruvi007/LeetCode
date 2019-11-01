def wildCard(s,p):
	n,m = len(s),len(p)
	dp = [ [False for j in range(0,m+1)] for i in range(0,n+1)]
	
	dp[0][0] = True
	for j in range(1,m+1):
		if p[j-1]=='*':
			dp[0][j] = dp[0][j-1]

	for i in range(1,n+1):
		for j in range(1,m+1):
			if p[j-1]==s[i-1] or p[j-1]=='?':
				dp[i][j] = dp[i-1][j-1]
			if p[j-1]=='*':
				dp[i][j] = dp[i-1][j] or dp[i][j-1]
	# print(dp)
	
	return dp[n][m]

s = input()
p = input()
ans = wildCard(s,p)
print(ans)


