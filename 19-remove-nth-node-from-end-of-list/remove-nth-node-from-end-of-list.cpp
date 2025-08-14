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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int total = 1;
        
        while(temp->next != NULL){
            temp = temp->next;
            total++;
        }

        int delNode = total - n + 1;

        if(delNode ==1){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int cnt = 1;
        temp = head;
        while(cnt < delNode - 1){
            temp = temp->next;
            cnt++;
        }
        ListNode* deletingNode = temp->next;
        temp->next = temp->next->next;
        delete deletingNode;

        return head;

    }
};