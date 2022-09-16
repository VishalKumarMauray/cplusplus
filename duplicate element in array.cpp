#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int a[10];
	cout<<"enter the element of array ";
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(a[j]==a[i])
			{
				cin>>a[j]<<" ";
				break;
			}
		}
	}
}
