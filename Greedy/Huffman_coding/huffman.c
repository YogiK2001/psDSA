#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the Huffman tree
struct Node
{
    char data;                 // Character stored in the node (for leaf nodes)
    int frequency;             // Frequency of the character
    struct Node *left, *right; // Left and right child pointers
};

// Function to create a new node
struct Node *newNode(char data, int frequency)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Function to swap two nodes during heap operations
void swapNodes(struct Node **a, struct Node **b)
{
    struct Node *t = *a;
    *a = *b;
    *b = t;
}

// Min Heap structure for the priority queue
struct MinHeap
{
    int size;            // Current size of the heap
    int capacity;        // Capacity of the heap
    struct Node **array; // Array of node pointers
};

// Function to create a new Min Heap node
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node **)malloc(capacity * sizeof(struct Node *));
    return minHeap;
}

// Function to heapify the heap
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx)
    {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the heap size is 1
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// Function to extract the minimum value node from the heap
struct Node *extractMin(struct MinHeap *minHeap)
{
    struct Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node into the heap
void insert(struct MinHeap *minHeap, struct Node *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

// Function to build the Huffman tree
struct Node *buildHuffmanTree(char data[], int frequency[], int size)
{
    struct Node *left, *right, *top;
    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insert(minHeap, newNode(data[i], frequency[i]));

    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print Huffman codes from the tree
void printCodes(struct Node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to perform Huffman encoding
void huffmanCodes(char data[], int frequency[], int size)
{
    struct Node *root = buildHuffmanTree(data, frequency, size);
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, arr, top);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    huffmanCodes(data, frequency, size);
    return 0;
}
