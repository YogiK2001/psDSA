// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Question: Detect Cycle in a Linked List
 *
 * Given a linked list, determine if it has a cycle in it.
 *
 * To represent a cycle in the given linked list, we use an integer pos which represents
 * the position (0-indexed) in the linked list where the tail connects to. If pos is -1,
 * then there is no cycle in the linked list.
 *
 * Example:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to the second node.
 */

class Solution
{
public:
    /**
     * This function detects if a cycle exists in a singly-linked list.
     * It uses Floyd's Tortoise and Hare algorithm to detect the cycle.
     *
     * @param head The head of the singly-linked list.
     * @return True if there is a cycle, otherwise false.
     */
    bool hasCycle(ListNode *head)
    {
        // Initialize two pointers, slow and fast, both starting at the head
        ListNode *slow = head, *fast = head;

        // Iterate through the list
        while (fast != nullptr && fast->next != nullptr)
        {
            // Move slow pointer one step
            slow = slow->next;
            // Move fast pointer two steps
            fast = fast->next->next;

            // If slow and fast pointers meet, there is a cycle
            if (slow == fast)
                return true;
        }

        // If we reach here, there is no cycle
        return false;
    }
};