#include <iostream>
#include <vector> // Include the vector header

using namespace std; // Use the std namespace

class MinHeap
{
private:
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void minHealify(int i)
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        if (i < 0 && heap[left] < heap[smallest])
            smallest = left;

        if (i < 0 && heap[right] > heap[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(heap[smallest], heap[i]);
            minHealify(smallest);
        }
    };
    // Bubble Up tyhe Heap
    void moveUp(int i)
    {
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    };

public:
    int findMin()
    {
        if (heap.empty())
        {
            return -1;
        }
        return heap[0];
    };

    void insert(int key)
    {
        heap.push_back(key);
        moveUp(heap.size() - 1);
    };

    int deleteMin()
    {
        if (heap.empty())
        {
            return -1;
        }

        int deleted = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            minHealify(heap[0]);

        return deleted;
    };

    bool deleteKey(int key)
    {
        int i;
        for (i = 0; i < heap.size(); i++)
        {
            if (heap[i] == key)
            {
                break;
            }
        }

        if (i == heap.size())
        {
            return false;
        }

        heap[i] = INT_MIN;

        moveUp(i);

        deleteMin();
        return true;
    };

    void printHeap()
    {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    };

    bool find(int key)
    {
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == key)
                return true;
        }
        return false;
    };
};

int main()
{
    // Example usage of vector
    vector<int> v1 = {20, 30, 40, 25, 15};
    MinHeap minHeap;
    int choice, value;

    while (true)
    {
        cout << "\nMin Heap Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Find Min\n";
        cout << "3. Delete Min\n";
        cout << "4. Delete Specific Key\n";
        cout << "5. Search Element\n";
        cout << "6. Print Heap\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            minHeap.insert(value);
            cout << "Inserted " << value << " into the heap\n";
            break;

        case 2:
            value = minHeap.findMin();
            if (value != INT_MAX)
                cout << "Minimum element is: " << value << endl;
            else
                cout << "Heap is empty\n";
            break;

        case 3:
            minHeap.deleteMin();
            cout << "Deleted minimum element from heap\n";
            break;

        case 4:
            cout << "Enter key to delete: ";
            cin >> value;
            if (minHeap.deleteKey(value))
                cout << "Successfully deleted " << value << " from heap\n";
            else
                cout << "Key " << value << " not found in heap\n";
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (minHeap.find(value))
                cout << value << " found in the heap\n";
            else
                cout << value << " not found in the heap\n";
            break;

        case 6:
            cout << "Heap elements: ";
            minHeap.printHeap();
            break;

        case 7:
            cout << "Exiting program\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
