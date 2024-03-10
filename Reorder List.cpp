#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            // If the list is empty or has only one node, no reordering needed.
            return;
        }

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* nextNode;

        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        printLinkedList(head);
        printLinkedList(prev);

        // prev now points to the reversed second half

        // Step 3: Merge the two halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;

        while (secondHalf->next) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }

    void printLinkedList(ListNode* head) {
        while (head) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
};



ListNode* createLinkedList(const std::initializer_list<int>& values) {
    ListNode* head = nullptr;
    ListNode* current = nullptr;

    for (int val : values) {
        if (!head) {
            head = new ListNode(val);
            current = head;
        } else {
            current->next = new ListNode(val);
            current = current->next;
        }
    }

    return head;
}



int main() {
    // Create a linked list with values [1, 2, 3, 4, 5]
    ListNode* head = createLinkedList({1, 2, 3, 4, 5});

    Solution sol;
    sol.reorderList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
