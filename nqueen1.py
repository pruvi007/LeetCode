def safe(board,col,row,n):

	for i in range(0,col):
		if board[row][i] == 'Q':
			return False
	
	l,r = row,col
	while l>=0 and r>=0:
		if board[l][r] == 'Q':
			return False
		l-=1
		r-=1
	l,r = row,col
	while l<n and r>=0:
		if board[l][r] == 'Q':
			return False
		l+=1
		r-=1
	return True

def nqueen(n,board,level,c,sol):
	if c == n:
		temp = []
		for x in board:
			temp.append(''.join(x))
		# print()
		sol.append(temp)
		return 
	for i in range(n):
		if safe(board,level,i,n):
			board[i][level] = 'Q'
			nqueen(n,board,level+1,c+1,sol)
			board[i][level] = '.'

n = int(input())
board = [ ['.' for j in range(n)] for i in range(n) ]
sol = []
nqueen(n,board,0,0,sol)
for b in sol:
	print(b)