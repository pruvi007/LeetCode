def trappingWater(a):
	
	n = len(a)
	ML,MR = [0]*n,[0]*n
	ML[0] = a[0]
	for i in range(1,n):
		if a[i] > ML[i-1]:
			ML[i] = a[i]
		else:
			ML[i] = ML[i-1]
	MR[n-1] = a[n-1]
	for i in range(n-2,0,-1):
		if a[i] > MR[i+1]:
			MR[i] = a[i]
		else:
			MR[i] = MR[i+1]
	water = 0
	# print(ML)
	# print(MR)
	for i in range(1,n-1):
		l,r = ML[i],MR[i]
		water += min(l,r) - a[i]
	return water

a = list(map(int,input().split()))
ans = trappingWater(a)
print(ans)
