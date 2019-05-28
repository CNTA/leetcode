#include <iostream>


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Runtime: 40 ms, faster than 47.76% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 14.9 MB, less than 53.68% of C++ online submissions for Add Two Numbers.
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL)
			return NULL;

		ListNode * result = new ListNode(0);
		result->val = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val);

		result->next = addTwoNumbers(
			l1 == NULL ? NULL : l1->next,
			l2 == NULL ? NULL : l2->next);

		if (result->val >= 10)
		{
			result->val -= 10;
			result->next = addTwoNumbers(result->next, new ListNode(1));
		}

		return result;
	}
};

int main()
{
	ListNode* l1 = new ListNode(1);

	ListNode* l2 = new ListNode(9);
	l2->next = new ListNode(9);
	l2->next->next = new ListNode(8);

	ListNode* result = Solution().addTwoNumbers(l1, l2);
	for (ListNode* t = result; t != NULL; t = t->next)
	{
		std::cout << t->val << " ";
	}

	return 0;
}
