//Write C++ program to store first year percentage of students in array. 
//Write function for sorting array of floating point numbers in ascending order 
//using a) Selection Sort  b) Bubble sort and display top five scores


#include<bits/stdc++.h>
using namespace std;


void selection(int n,int a[])
{
	int tmp=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	cout<<"\nSorted array is: \n\t";
	for(int k=0;k<n;k++)
	cout<<a[k]<<" ";
}

void bubble(int n,int a[])
{
	int tmp=0;
	for(int k=1;k<n;k++)
	{
		for(int i=0;i<n-k;i++)
		{
			if(a[i]>a[i+1])
			{
				tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
			}
		}
	}
	
	cout<<"\nSorted array is: \n\t";
	for(int j=0;j<n;j++)
	cout<<a[j]<<" ";
	
}

void insertion(int n,int a[])
{
	int temp,i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0 && a[j]>temp;j--)
		   a[j+1]=a[j];
		a[j+1]=temp; 
	      	
	}
	
	cout<<"\nSorted array is: \n\t";
	for(int k=0;k<n;k++)
	cout<<a[k]<<" ";
}

void shell(int n,int a[])
{
	int temp=0,d,i,j,k;
	for(d=n/2;d>0;d=d/2)
	{
		for(i=d;i<n;i++)
		{
			for(j=i;j>=d;j=j-d)
			{
				if(a[j]<a[j-d])
				{
					temp=a[j];
					a[j]=a[j-d];
					a[j-d]=temp;
					
				}
				else
				break;
			}
		}
	}
	
	cout<<"\nSorted array is: \n\t";
	for(k=0;k<n;k++)
	cout<<a[k]<<" ";
}

int main()
{
	int n,op;
	cout<<"\nEnter the number of students::: ";
	cin>>n;
	int a[n];
	
	cout<<"\nEnter their marks";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	char ch;
	
	do
	{
		cout<<"\nChoose the Sorting you want to use:";
		cout<<"\n1.selection sort";
		cout<<"\n2.bubble sort";
		cout<<"\n3.insertion sort";
		cout<<"\n4.shell sort\n";
		
		cin>>op;
		switch(op)
		{
			case 1:selection(n,a);
			       break;
			case 2:bubble(n,a);
			       break;
	        case 3:insertion(n,a);
			       break;
	        case 4:shell(n,a);
			       break;	
		    default:cout<<"\nwrong option !! exiting...";		
			        return 0;   		   			          
		}
		cout<<"\nDo you want to continue(y/n)";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	
	
}
