def missingPositive(a):
	n = len(a)
    # step-1 segregate negative and positive elements
    j = 0
    for i in range(n):
        if a[i] <= 0:
            temp = a[i]
            a[i] = a[j]
            a[j] = temp
            j += 1

    # index j will be the start of positive part of the array
    # print(j)
    # step2- mark the presence of a[i] by making a[a[i]-1] to negative
    a = a[j:n]
    print(a)
    n = len(a)
    for i in range(n):
        if abs(a[i])<=(n) and a[ abs(a[i])-1 ]>0:
            a[ abs(a[i])-1 ] = -a[ abs(a[i])-1 ]
    print(a)
    c= 0 
    for i in range(n):
        if a[i] > 0:
            return i+1
    return n+1

a = list( map(int,input().split()) )
ans = missingPositive(a) 
print(ans)