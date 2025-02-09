//Demonstrate the solution for Tower of Hanoi problem.

#include<iostream>
using namespace std;

void hanoiTower(int n, char src, char dst, char help)
{
	if(n==0)
	{
		return;
	}
	else
	{
		hanoiTower(n-1,src, help, dst);
		cout<<"Move Disk "<<n<<" from "<<src<<" to "<<dst<<endl;
		hanoiTower(n-1, help, dst, src);
	}
}

void main()
{
	int n;
	cout<<"Enter the number of Disks: ";
	cin>>n;
	hanoiTower(n, 'A','C','B');
}
