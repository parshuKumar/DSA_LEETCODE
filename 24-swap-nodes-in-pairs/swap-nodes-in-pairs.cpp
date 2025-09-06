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
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = head;
        ListNode* prev = NULL;
        while(first != NULL && first->next != NULL){
            ListNode* second = first->next;
            first->next = second->next;
            second->next = first;
            

            if(prev == NULL){
                head = second;
            }
            else{
                prev->next = second;
            }
            prev = first;
            first = first->next;

        }
        return head;
    }
};