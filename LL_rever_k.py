class ListNode:
	def __init__(self,x):
		self.val = x
		self.next = None
def insert(head,x):
	if head==None:
		return ListNode(x)
	temp = head
	while temp.next:
		temp=temp.next
	temp.next = ListNode(x)
	return head
def printList(head):
	temp = head
	while temp:
		print(temp.val,end='->')
		temp = temp.next
	print("None")

def reverseK(head,k):
	cur,n,prev = head,None,None
	c = 0
	while cur!=None and c!=k:
		n = cur.next
		cur.next = prev
		prev = cur
		cur = n
		c+=1
	if n!=None:
		head.next = reverseK(n,k)
	return prev
a = list(map(int,input().split()))
k = int(input())
head = ListNode(0)
for x in a:
	head = insert(head,x)
printList(head.next)

ans = reverseK(head.next,k)
printList(ans)