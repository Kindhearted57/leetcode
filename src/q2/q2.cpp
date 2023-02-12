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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // Initialize the result linked list;
        ListNode * ans = new ListNode(0, NULL);
        ListNode * result = ans;
        while(l1!=NULL || l2!= NULL || carry != 0){
            int l1_value = l1? l1 -> val: 0;
            int l2_value = l2? l2 -> val: 0;
            int sum = l1_value + l2_value + carry;
            carry = sum/10;

            ListNode * temp = new ListNode(sum%10, NULL);
            result -> next = temp;
            result = result -> next;
            l1 = l1? l1->next:NULL;
            l2 = l2? l2->next:NULL;
        }
        return ans -> next;
    }
};
