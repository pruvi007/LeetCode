def genParen(s,open,close,n):
	if close == n:
		print(''.join(s))
		return 
	else:
		if open > close:
			s.append(')')
			genParen(s,open,close+1,n)
			s.pop()
		if open < n:
			s.append('(')
			genParen(s,open+1,close,n)
			s.pop()
		


n = int(input())
genParen([],0,0,n)
