#include <iostream>

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /**
     * This function reverses a singly-linked list.
     *
     * @param head The head of the singly-linked list.
     * @return The new head of the reversed singly-linked list.
     */
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head; // Initialize the current node to the head of the list
        ListNode *prev = NULL; // Initialize the previous node to NULL

        // Iterate through the list until the end is reached
        while (curr != nullptr)
        {
            ListNode *next = curr->next; // Store the next node
            curr->next = prev;           // Reverse the current node's pointer
            prev = curr;                 // Move the previous node to the current node
            curr = next;                 // Move the current node to the next node
        }

        // At the end of the loop, prev will be the new head of the reversed list
        return prev;
    }
};

int main()
{
    // Example usage
    Solution solution;

    // Creating a linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Reversing the linked list
    ListNode *reversedHead = solution.reverseList(head);

    // Printing the reversed linked list
    ListNode *curr = reversedHead;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;

    return 0;
}