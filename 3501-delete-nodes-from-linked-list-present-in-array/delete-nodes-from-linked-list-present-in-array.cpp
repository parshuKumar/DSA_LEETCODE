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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        
        while(head != NULL){
            if(st.contains(head->val)){
                head = head->next;
            }else{
                break;
            }
        }

        ListNode* cur = head;
        ListNode* prev = cur;

        while(cur != NULL){
            if(st.contains(cur->val)){
                prev->next = cur->next;
                // delete cur;
                cur = prev->next;
            }else{  
                prev = cur;
                cur = cur->next;
            }
            
        }

        return head;
    }
};