def regexMatch(s,p):
	s, p = ' '+ s, ' '+ p
	lenS, lenP = len(s), len(p)
	dp = [[False]*(lenP) for i in range(lenS)]
	dp[0][0] = True

	for j in range(1, lenP):
		if p[j] == '*':
			dp[0][j] = dp[0][j-2]

	for i in range(1, lenS):
		for j in range(1, lenP):
			if p[j] in {s[i], '.'}:
				dp[i][j] = dp[i-1][j-1]
			elif p[j] == "*":
				dp[i][j] = dp[i][j-2] or (dp[i-1][j] and p[j-1] in {s[i], '.'})

	return bool(dp[-1][-1])

s,p = input(),input()

ans = regexMatch(s,p)
print(ans)