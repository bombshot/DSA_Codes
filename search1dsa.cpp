#include<bits/stdc++.h>
using namespace std;


void linear(int n,int x,int a[])
{
	int i=0;
	while(i<n)
	{
		if(a[i]==x)
		{
			cout<<"\n\tFound at position "<<i;
			return;
		}
		i++;
	}
	cout<<"\n\tSorry!!!...Not Found";
	
}

void binary(int n,int x,int a[])
{
	int i,mid,x1,y1;
	x1=0;
	y1=n-1;
	
	while(x1<=y1)
	{
	   mid=(x1+y1)/2;
	   
	   if(a[mid]==x)
	   {
	   	cout<<"\n\tFound at "<<mid;
	   	return;
	   }	
	   else if(a[mid]>x)
	   {
	   	y1=mid-1;
	   }
	   else if(a[mid]<x)
	   {
	   	x1=mid+1;
	   }
	}
	cout<<"\nNot Found";
}

void sentinel(int n,int x,int a[])
{
	int i=0;
	a[n]=x;
	while(a[i]!=x)
	{
		i++;
	}
	if(i!=n)
	{
		cout<<"\n\tFound at "<< i;
	}
	else
	cout<<"\nSorry...Not Found";
}

int fib(int k)
{
	if(k==0) return 0;
	if(k==1) return 1;
	return(fib(k-1)+fib(k-2));
}

void fibonacci(int n,int x,int a[],int mid,int p,int q)
{
	int temp;
	
	if(x==a[mid-1])
	{
		cout<<"\n\tFound at"<<mid-1;
		return;
	}
	if(x>a[mid-1])
	{
		if(p==1)
		{
			cout<<"\nNot Found";
			return;
		}
		mid=mid+q;
		p=p-q;
		q=q-p;
		return(fibonacci(n,x,a,mid,p,q));
	}
	else 
	{
		if(q==0)
		{
			cout<<"\nNot Found";
			return ;
		}
		mid=mid-q;
		temp=p-q;
		p=q;
		q=temp;
		return(fibonacci(n,x,a,mid,p,q));
	}
}

int main()
{
    int n,i,x,p,q,mid;
    cout<<"\nEnter the number of students:: ";
    cin>>n;
    int a[n+1];
    cout<<"\nEnter their roll numbers: ";
    
    int op;
    char ch;
    for(i=0;i<n;i++)
    cin>>a[i];
    
    do
    {
    	cout<<"\nChoose an algorithm:";
    	cout<<"\n1.Linear search";
    	cout<<"\n2.Binary search";
    	cout<<"\n3.Sentinel search";
    	cout<<"\n4.Fibonacci search\n";
    	
    	cin>>op;
    	switch(op)
    	{
    		case 1:cout<<"\nEnter the roll number you're searching for: ";
    		       cin>>x;
    		       linear(n,x,a);
    		       break;
    		case 2:cout<<"\nEnter the roll number you're searching for: ";
    		       cin>>x;
				   binary(n,x,a);
				   break;
		    case 3:cout<<"\nEnter the roll number you're searching for: ";
    		       cin>>x;
				   sentinel(n,x,a);
				   break;
	        case 4:cout<<"\nEnter the roll number you're searching for: ";
    		       cin>>x;
    		       for(i=1;fib(i)<=n;i++);
    		       p=fib(i-2);
    		       q=fib(i-3);
    		       mid=n-p+1;
    		       fibonacci(n,x,a,mid,p,q);
				   break;
		    default:cout<<"!! wrong option !!  exiting...";
			        return 0;			   		          
		}
    	cout<<"\n\nDo you want to continue(y/n)";
    	cin>>ch;
    	
	}while(ch=='y'|| ch=='Y');





}


