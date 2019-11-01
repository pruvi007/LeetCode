def isPresent(a,x,l,r):
	while l<=r:
		mid = (l+r)//2
		if a[mid] == x:
			return True
		elif a[mid] > x:
			r = mid-1
		else:
			l = mid+1
	return False

# O(n^2)
# for each ith element use 2 pointers to get the result
# we can use binary search as well but that will be n^2lg(n)
def _3sum(a):
	a = sorted(a)
	n = len(a)
	triplets = set()
	for i in range(n):
		pivot = -a[i]
		l, r = i+1, n-1
		while l<r:
			if a[l] + a[r] == pivot:
				triplets.add( (a[i],a[l],a[r]) )
				l += 1
				r -= 1
			elif a[l] + a[r] > pivot:
				r-=1
			else:
				l+=1
	L = []
	for x in triplets:
		L.append( [x[0],x[1],x[2]] )
	return L

n = int(input())
a = list(map(int,input().split()))
ans = _3sum(a)

print(ans)
