class Solution
{
public:
    ListNode *reverse(ListNode *start, ListNode *end)
    {
        ListNode *prev = nullptr;
        ListNode *cur = start;
        ListNode *next = nullptr;
        while (cur != end)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *preveG = &dummy;
        while (true)
        {
            ListNode *start = preveG->next;
            ListNode *end = preveG;

            for (int i = 0; i < k && end; ++i)
                end = end->next;

            if (!end)
                break;

            ListNode *nextS = end->next;
            ListNode *reveH = reverse(start, end->next);
            preveG->next = reveH;
            start->next = nextS;
            preveG = start;
        }
        return dummy.next;
    }
};
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size(), m = needle.size();
        if (m == 0)
            return 0;
        for (int i = 0; i <= n - m; i++)
        {
            if (haystack.substr(i, m) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};