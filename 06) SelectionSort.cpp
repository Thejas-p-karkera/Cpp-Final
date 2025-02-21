// Implement selection sort to arrange a list of integers in descending order and find ith largest element in the given list.


#include<iostream>
using namespace std;

int main()
{
	int n, i;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int* arr = new int[n];

	cout<<"Enter "<<n<<" elements into the array :";
	for(int i=0; i<n ;i++)
	{
		cin>>arr[i];
	}

	cout<<"The elements in the array before sorting: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}

	//selection sort
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i]>arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout<<"\nThe elements in the array after sorting: ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}

	cout<<"\nEnter the value for i (to find i-th largest element): ";
	cin>>i;

	if(i<1 || i>n)
	{
		cout<<"Invalid value for i"<<endl;
	}
	else
	{
		cout<<i<<"-th largest element is: "<<arr[i-1]<<endl;
	}

	return 0;
}
