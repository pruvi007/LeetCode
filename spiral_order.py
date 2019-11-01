def spiral(a):
	if len(a)==0:
		return []
	n,m = len(a),len(a[0])
	rs,rl = 0,n
	cs,cl = 0,m
	c = 0
	l = []
	while rs<rl and cs<cl:
		# print row from left - right
		for i in range(cs,cl):
			# print(a[rs][i],end=' ')
			l.append(a[rs][i])
			c+=1
		# print()
		rs+=1
		if c == n*m:
			break
		# print column from top-bottom
		for i in range(rs,rl):
			# print(a[i][cl-1],end=' ')
			l.append(a[i][cl-1])
			c+=1
		# print()
		cl-=1
		if c == n*m:
			break
		# print row from right-left
		for i in range(cl-1,cs-1,-1):
			# print(a[rl-1][i],end=' ')
			l.append(a[rl-1][i])
			c+=1
		# print()
		rl-=1
		if c == n*m:
			break
		# print column to bottom-top
		for i in range(rl-1,rs-1,-1):
			# print(a[i][cs],end=' ')
			l.append(a[i][cs])
			c+=1
		# print()
		cs+=1
		if c == n*m:
			break
	return l


n,m = map(int,input().split())
a = []
for i in range(n):
	a.append( list( map(int,input().split()) ) )
ans = spiral(a)
print(ans)
