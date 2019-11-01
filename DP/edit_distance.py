def editDistance(word1,word2):
	n,m = len(word1),len(word2)
	dp = [[0 for j in range(m+1)] for i in range(n+1)]
	dp[0][0] = 0
	for i in range(1,m+1):
		dp[0][i] = i
	for i in range(1,n+1):
		dp[i][0] = i

	for i in range(1,n+1):
		for j in range(1,m+1):
			if word1[i-1] == word2[j-1]:
				dp[i][j] = dp[i-1][j-1]
			else:
				d = 1 + dp[i-1][j]
				ins = 1 + dp[i][j-1]
				rep = 1 + dp[i-1][j-1]
				dp[i][j] = min( d,min(ins,rep) )
	return dp[-1][-1]

word1,word2 = input().split()
ans = editDistance(word1,word2)
print(ans)