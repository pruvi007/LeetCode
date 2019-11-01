class ListNode:
	def __init__(self,x):
		self.val = x
		self.next = None

def insert(head,x):
	if head == None:
		return ListNode(x)
	temp = head
	while temp.next:
		temp = temp.next
	n = ListNode(x)
	temp.next = n
	return head

def printList(head):
	temp = head
	while temp:
		print(temp.val,end='->')
		temp = temp.next
	print("None")

def swapPairs(head):
	cur,n,prev = head,head,None
	c = 0
	while cur!=None and c!=2:
		n = cur.next
		cur.next = prev
		prev = cur
		cur = n
		c += 1
	if n!=None:
		head.next = swapPairs(n)
	return prev


a = list(map(int,input().split()))
head = ListNode(0)
for x in a:
	head = insert(head,x)
printList(head.next)

ans = swapPairs(head.next)
printList(ans)
