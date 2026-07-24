/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        ListNode* curr = head;
        ListNode* prev = nullptr;
        int carry = 0;

        while (curr) {
            int sum = curr->val * 2 + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            prev = curr;
            curr = curr->next;
        }

        if (carry)
            prev->next = new ListNode(carry);

        return reverse(head);
    }
};