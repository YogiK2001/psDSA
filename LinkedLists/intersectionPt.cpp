// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * This function finds the intersection point of two singly-linked lists.
     * It assumes that the first list is longer by 'd' nodes.
     *
     * @param d The difference in length between the two lists.
     * @param head1 The head of the first linked list.
     * @param head2 The head of the second linked list.
     * @return The intersection node, or nullptr if there is no intersection.
     */
    ListNode *getIntersection(int d, ListNode *head1, ListNode *head2)
    {
        // Initialize two pointers for both lists
        ListNode *current1 = head1;
        ListNode *current2 = head2;

        // Move the pointer of the longer list 'd' steps ahead
        for (int i = 0; i < d; i++)
        {
            // If the longer list is shorter than expected, return nullptr
            if (current1 == nullptr)
            {
                return nullptr;
            }
            current1 = current1->next;
        }

        // Traverse both lists together until the intersection is found
        while (current1 != nullptr && current2 != nullptr)
        {
            // If the nodes are the same, return the intersection node
            if (current1 == current2)
                return current1;

            // Move both pointers one step forward
            current1 = current1->next;
            current2 = current2->next;
        }

        // If no intersection is found, return nullptr
        return nullptr;
    }
};