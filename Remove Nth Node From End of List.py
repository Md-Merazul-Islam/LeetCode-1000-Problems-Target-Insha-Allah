# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        tmp = ListNode(0, head)
        first = tmp
        scnd = tmp

        for i in range(n+1):
            first = first.next

        while first:
            first = first.next
            scnd = scnd.next

        scnd.next = scnd.next.next

        return tmp.next
