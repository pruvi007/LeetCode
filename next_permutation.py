def  nextPerm(a):
	n = len(a)
	# 1. find the index where a[i] > a[i+1] 
	i = n-2
	st = -1
	while i>=0:
		if a[i] < a[i+1]:
			st = i
			break
		i-=1
	if st == -1:
		return ''.join(sorted(a))



	# 2. find the index j, j >= i such that a[j] > a[i]
	i = n-1
	end = -1
	while i>st:
		if a[i] > a[st]:
			end = i
			break
		i-=1

	# 3 swap a[j] and a[i]
	temp = a[st]
	a[st] = a[end]
	a[end] = temp

	# 4. reverse the suffix from a[i] to a[n-1]
	rev = []
	for i in range(st+1,n):
		rev.append(a[i])
	c = st+1
	i = len(rev)-1
	while i>=0:
		a[c] = rev[i]
		c+=1
		i-=1
	return ''.join(a)


s = input()
l = [s[i] for i in range(len(s))]
ans = nextPerm(l)
print(ans)

