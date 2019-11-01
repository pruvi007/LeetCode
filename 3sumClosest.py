
def _3sumClosest(a,target):
	a = sorted(a)
	n = len(a)
	triplets = []
	for i in range(n):
		pivot = target-a[i]
		l, r = i+1, n-1
		while l<r:
			if a[l] + a[r] == pivot:
				triplets.append( (0,a[i],a[l],a[r]) )
				l += 1
				r -= 1
			elif a[l] + a[r] > pivot:
				d = abs(target - (a[i]+a[l]+a[r]) )
				triplets.append( (d,a[i],a[l],a[r]) )
				r-=1
			else:
				d = abs(target - (a[i]+a[l]+a[r]) )
				triplets.append( (d,a[i],a[l],a[r]) )
				l+=1
	triplets = sorted(triplets)
	print(triplets)
	x = triplets[0]
	return x[1] + x[2] + x[3]  

n = int(input())
a = list(map(int,input().split()))
target = int(input())
ans = _3sumClosest(a,target)
print(ans)


