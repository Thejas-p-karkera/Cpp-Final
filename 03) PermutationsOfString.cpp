//Generate all permutations of the characters in a given string.

#include<iostream>
#include<string>
using namespace std;

void permute(string str, int l, int r)
{
	if(l==r)
	{	
		cout<<count<<" : "<<str<<endl;
	}
	else
	{
		for(int i=l; i<=r; i++)
		{
			swap(str[i],str[l]);		//swap characters	
			permute(str, l+1, r);		//Recursive call	
			swap(str[i],str[l]);		//Backtracak to the original string
		}
	}

}

void main()
{
	string str;
	cout<<"Enter a string to get its permutations: ";
	cin>>str;
	permute(str, 0 ,str.length()-1);
}
