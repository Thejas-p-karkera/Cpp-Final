//Implement the following operations on one dimensional array of integers: Insertion, Deletion, Search, Sort, and Reverse.

#include <iostream>
using namespace std;

// Function to display the array
void display(int arr[], int& size)
{
    if (size == 0)
    {
        cout << "Array is empty.\n";
        return;
    }
    else
    {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    
    cout << endl;
}

// Function to insert an element to the array
void insert(int arr[], int& size, int MAX_SIZE)
{
    int element;
    cout << "Enter the element to insert: ";
    cin >> element;

    if (size >= MAX_SIZE)
    {
        cout << "Array is full!\n";
        return;
    }
    else
    {
        arr[size] = element;
        size++;
    }
    
    cout << "Element inserted successfully.\n";
}

// Function to delete an element at a specific position
void deleteElement(int arr[], int& size)
{
    int position;
    cout << "Enter the position of the element to delete (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size)
    {
        cout << "Invalid position!\n";
        return;
    }
    else
    {
        for (int i = position; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }

    size--;
    cout << "Element deleted successfully.\n";
}

// Function to search for an element in the array
void search(int arr[], int& size)
{
    int element;
    cout << "Enter the element to search: ";
    cin >> element;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            cout << "Element " << element << " found at position " << i+1 << ".\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

// Function to sort the array
void sort(int arr[], int& size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Array sorted successfully.\n";
}

// Function to reverse the array
void reverse(int arr[], int& size)
{
    int strt = 0;
    int end = size-1;

    while (strt < end)
    {
        swap(arr[strt], arr[end]);
        strt++;
        end--;
    }

    cout << "Array reversed successfully.\n";
}

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while(true)
    {
        // Menu-driven interface
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Search for an element\n";
        cout << "4. Sort the array\n";
        cout << "5. Reverse the array\n";
        cout << "6. Display the array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                    insert(arr, size, MAX_SIZE);
                    break;

            case 2:
                    deleteElement(arr, size);
                    break;

            case 3:
                    search(arr, size);
                    break;

            case 4:
                    sort(arr, size);
                    break;

            case 5:
                    reverse(arr, size);
                    break;

            case 6:
                    display(arr, size);
                    break;

            case 7:
                    // Exit
                    cout << "Exiting the program.\n";
                    break;

            default:
                    cout << "Invalid choice. Please try again.\n";
        }
    } 

    return 0;
}
