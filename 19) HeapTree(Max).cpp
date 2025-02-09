// Implement (max/min) heap tree (Insertion and deletion operations).

#include <iostream>
using namespace std;

// Heapify Up: Restores the heap property by moving a node up
void heapifyUp(int arr[], int i)
{
    int parent = (i - 1) / 2; // Parent index

    if (parent >= 0 && arr[i] > arr[parent])
    {
        swap(arr[i], arr[parent]);
        heapifyUp(arr, parent); // Recursive call to continue heapifying up
    }
}

// Heapify Down: Restores the heap property by moving a node down
void heapifyDown(int arr[], int index, int root)
{
    int largest = root;            // Assume current node is the largest
    int leftChild = 2 * root + 1;  // Left child index
    int rightChild = 2 * root + 2; // Right child index

    // Check if the left child exists and is greater than the current largest
    if (leftChild <= index && arr[leftChild] > arr[largest])
        largest = leftChild;

    // Check if the right child exists and is greater than the current largest
    if (rightChild <= index && arr[rightChild] > arr[largest])
        largest = rightChild;

    // If the largest is not the current node, swap and heapify down
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapifyDown(arr, index, largest);
    }
}

// Insert a new node into the heap
void insertNode(int arr[], int& index, int key)
{
    index++;                // Increment size
    arr[index] = key;       // Add the new key at the end of the heap
    heapifyUp(arr, index);  // Restore the heap property
}

// Delete the root element from the heap
void deleteRoot(int arr[], int& index)
{
    if (index < 0)
    {
        cout << "Heap is empty. Cannot delete." << endl;
        return;
    }

    arr[0] = arr[index]; // Replace root with last element
    index--;             // Reduce the size of the heap
    heapifyDown(arr, index, 0); // Restore the heap property
}

// Utility function to print the heap array
void printHeap(int arr[], int index)
{
    if (index < 0)
    {
        cout << "Heap is empty." << endl;
        return;
    }
    for (int i = 0; i <= index; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    const int MAX = 100;
    int arr[MAX]; // Array to store the heap
    int index = -1;   // Size of the heap (initially empty)

    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Root Element\n";
        cout << "3. Print Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int key;
            cout << "Enter the element to insert: ";
            cin >> key;
            insertNode(arr, index, key);
            cout << "Element inserted successfully.\n";
            break;
        }
        case 2:
            deleteRoot(arr, index);
            cout << "Root element deleted successfully.\n";
            break;
        case 3:
            cout << "Heap contents: ";
            printHeap(arr, index);
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
