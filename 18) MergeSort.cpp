#include <iostream>
using namespace std;

// Function to merge two sorted halves into a single sorted array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;  // Size of left sub-array
    int n2 = right - mid;     // Size of right sub-array

    // Create temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];  // Copy elements from left half
    }

    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];  // Copy elements from right half
    }

    int i = 0, j = 0, k = left; // i -> leftArr index, j -> rightArr index, k -> main array index

    // Merge the two halves back into arr[]
    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i]; // Take smaller element from left array
            i++;
        }
        else
        {
            arr[k] = rightArr[j]; // Take smaller element from right array
            j++;
        }
        k++;
    }

    // Copy any remaining elements from leftArr
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements from rightArr
    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)       // Base condition to stop recursion
    {
        int mid = left + (right - left) / 2; // Find the middle point

        mergeSort(arr, left, mid);     // Recursively sort the left half
        mergeSort(arr, mid + 1, right); // Recursively sort the right half

        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() 
{
    int size;

    // Taking user input for array size
    cout << "Enter the number of elements: ";
    cin >> size;

    int* arr = new int[size]; // Declaring array

    // Taking user input for array elements
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, size); // Print original array

    mergeSort(arr, 0, size - 1); // Call merge sort

    cout << "Sorted array: ";
    printArray(arr, size); // Print sorted array

    return 0;
}
