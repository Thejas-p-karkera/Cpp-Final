// Implement Binary search (Recursive and iterative versions).

#include<iostream>
using namespace std;

int BinarySearch(int arr[], int strt, int end, int key)
{
	while (strt <= end)
	{
		int mid = (strt + end) / 2;

		if (arr[mid] == key)
		{
			return mid;
		}
		else if (key > arr[mid])
		{
			strt = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}

void main()
{
	int arr[] = { 1,3,5,7,9,11 };
	int size = sizeof(arr);

	int key;
	cout << "Enter the search key: ";
	cin >> key;

	int result = BinarySearch(arr, 0, size - 1, key);

	if (result == -1)
	{
		cout << "Element not found";
	}
	else
	{
		cout << "element found at position " << result;
	}

}
