class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        l1_num = 0
        l2_num = 0

        digit = 1
        while l1 != None:
            l1_num += l1.val * digit
            digit *= 10
            l1 = l1.next
        digit = 1
        while l2 != None:
            l2_num += l2.val * digit
            digit *= 10
            l2 = l2.next

        number = l1_num + l2_num
        if number == 0 :
            return ListNode(0)
        print(number)
        ret = ListNode(0)
        cur = ret
        while number != 0:
            newNode = ListNode(number%10)
            number = int(number/10)
            cur.next = newNode
            cur = newNode
            
        return ret.next


l1 = ListNode(2, ListNode(4, ListNode(3)))

l2 = ListNode(5, ListNode(6, ListNode(4)))

print(Solution().addTwoNumbers(l1, l2))