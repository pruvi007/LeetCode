def minWindow(s,t):
	n,m = len(s),len(t)
	f1 = [0]*26
	for alpha in t:
		f1[alpha%97]+=1
	low,high = 0,n-1
	ans = -1
	while low<=high:
		mid = (low+high)//2
		f2 = [0]*26
		valid = False
		for i in range(mid):
			f2[s[i]%97]+=1
		for i in range(mid,n):
			if freqSame(f1,f2):
				valid = True
				break
			f2[s[i-mid]%97]-=1
			f2[s[i]%97]+=1
		if valid:
			ans = mid
			high = mid-1
		else:
			low = mid+1
	return ans