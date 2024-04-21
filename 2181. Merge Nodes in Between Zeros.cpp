class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr; 
        
        head = head->next;

        ListNode* current = head;
        ListNode* prev = head; 
        double sum = 0;

        while (current) {
            if (current->val == 0){
                prev->val = sum;
                if (current->next)
                    prev = prev->next;
                sum = 0;
            } else {
                sum += current->val;
            }
            current = current->next;
        }
        prev->next = nullptr;
        return head;
    }
};
