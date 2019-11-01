'''
Backtracking approach for word Ladder2 -> TLE
BFS approach for this
'''

def valid(a,b):
	c=0
	for i in range(len(a)):
		if a[i]!=b[i]:
			c+=1
	return c==1

def word_ladder(cur,e,words,temp,trans):
	if e in temp:
		# print(temp)
		trans.append(temp[:])
		return 
	for i in range(0,len(words)):
		if valid(cur,words[i]):
			if words[i] not in temp:
				temp.append(words[i])
				word_ladder(words[i],e,words,temp,trans)
				temp.pop()

begin,end = input().split()
words = input().split()

trans = []
word_ladder(begin,end,words,[begin],trans)

# print(trans)
minLen = 999999
for l in trans:
	if len(l)<minLen:
		minLen = len(l)

ans = []
for l in trans:
	if len(l) == minLen:
		ans.append(l)
print(ans)

