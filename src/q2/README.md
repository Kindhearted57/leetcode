## First Thought

My first thought is to turn the linked list into an integer -> sum up the two integers -> create a new linked list.

This idea has trouble dealing with input with long digits, ends up getting runtime error:

```
Runtime Error
Line 18: Char 18: runtime error: 1e+30 is outside the range of representable values of type 'long' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:27:18
Last Executed Input
[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
[5,6,4]
```

```
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
        int factor = 0;
        int64_t sum1 = 0;
        ListNode * item1 = l1;
        while(item1 != NULL){
            sum1 += item1-> val * (pow(10, factor));
            item1 = item1 -> next;
            factor ++;
        }
       

        ListNode * item2 = l2;
        factor = 0;
        int64_t sum2 = 0;
        while(item2 != NULL){
            sum2 += item2 -> val * (pow(10, factor));
            item2 = item2 -> next;
            factor ++;
        }
        
        
        ListNode * result =  new ListNode(0);
        ListNode * ans = result;
        result -> next = NULL;
        int64_t sum = sum1 + sum2;
        cout << sum;
        do{
            cout << sum%10;
            ListNode * temp = new ListNode(sum%10);
            temp->next = NULL;
            result -> next = temp;
            result = result -> next;
            sum = sum / 10;
        }while(sum > 0);
        
        return ans->next;
    }
};
```

The solution is to abandon this approach and follow the one in the official solution.
