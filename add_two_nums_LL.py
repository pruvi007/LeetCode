class ListNode:
	def __init__(self,x):
		self.val = x;
		self.next = None

class Solution:
	def addTwoNumbers(self,l1:ListNode,l2:ListNode) -> ListNode:
		ans = ListNode(0)
        temp1, temp2 = l1,l2
        if temp1==None:
            return temp2
        elif temp2==None:
            return temp1
        
        # here i am appending 0's to the number with smaller digits length
        while temp1.next or temp2.next:
            if temp1.next == None and temp2!=None:
                x = ListNode(0)
                temp1.next = x
            elif temp2.next == None and temp1!=None:
                x = ListNode(0)
                temp2.next = x
            temp1 = temp1.next
            temp2 = temp2.next

        temp1,temp2 = l1,l2
        # while temp1:
        #     print(temp1.val,end='->')
        #     temp1 = temp1.next
        # print()
        # while temp2:
        #     print(temp2.val,end='->')
        #     temp2 = temp2.next
        # print()
        carry = 0
        temp3 = ans
        while temp1 and temp2:
            sum = temp1.val + temp2.val + carry
            
            if sum <= 9:
                carry = 0
            else:
                sum = sum -10
                carry = 1
            x = ListNode(sum)
            temp3.next = x
            temp3 = temp3.next
            temp1 = temp1.next
            temp2 = temp2.next
        if carry==1:
            x = ListNode(1)
            temp3.next = x
        return ans.next
