// Implement Binary search (Recursive and iterative versions).

#include<iostream>
using namespace std;

int binarSearch(int arr[], int strt, int end, int key)
{
	if (strt > end)
	{
		return -1;
	}

	int mid = (strt + end) / 2;

	if (arr[mid] == key)
	{
		return mid;
	}
	else if (key > arr[mid])
	{
		strt = mid + 1;
		return binarSearch(arr, strt, end, key);
	}
	else
	{
		end = mid - 1;
		return binarSearch(arr, strt, end, key);
	}

}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};

	int n =  sizeof(arr);

	int key;
	cout << "Enter the search key: ";
	cin >> key;

	int result = binarSearch(arr, 0, n-1, key);

	if (result == -1)
	{
		cout << "Element not found";
	}
	else
	{
		cout << "element found at position " << result;
	}
}
