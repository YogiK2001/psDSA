struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // code here
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            /* compute the depth of each subtree */
            int lDepth = height(node->left);
            int rDepth = height(node->right);

            /* use the larger one */
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }
};