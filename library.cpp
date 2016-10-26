#include<iostream>
using namespace std;
class library
{	int p[100],n,q[100];
	public:
		void get();			
		void reverse();
		void less();
		void more();
		void d1();
		void d2();
};
void library::get()
{	 cout<<"Enter the no of books :";
	cin>>n;
	cout<<"Enter the price of books :";
	for(int i=0;i<n;i++)
		cin>>p[i];
}
void library::reverse()
{	for(int i=0,j=n-1;i<=j;i++,j--)
	{	int temp=p[i];
		p[i]=p[j];
		p[j]=temp;
	}	
	cout<<"\nThe price of books in reverse order :";
	for(int i=0;i<n;i++)
		cout<<p[i]<<" ";
}
void library::less()
{	cout<<"\nThe list of books having price less than 500 :";
	for(int i=0;i<n;i++)
	{	if(p[i]<500)
		cout<<p[i]<<" ";
	}
}
void library::more()
{	cout<<"\nThe list of books having price greater or equal to 500:";
	for(int i=0;i<n;i++)
	{	if(p[i]>=500)
		cout<<p[i]<<" ";
	}
}
void library::d1()
{	for(int i=0;i<n-1;i++)
	{	if(p[i]==p[i+1])
		{	for(int j=i+2;j<n;j++)
			{	p[j-1]=p[j];
				
			}
			n--;
			i--;
		}
	}
	cout<<"\nList with no duplicte item :";
	for(int i=0;i<n;i++)
	cout<<p[i]<<" ";
}
void library::d2()
{	int a[100],k=1;
	a[0]=p[0];
	for(int i=0;i<n-1;i++)
	{	if(p[i]!=p[i+1])
		a[k++]=p[i+1];
	}
	cout<<"\nList with no duplicte item (using temp array):";
	for(int i=0;i<k;i++)
	cout<<a[i]<<" ";
}
int main()
{	library l;
	l.get();
	l.reverse();
	l.less();
	l.more();
	l.d1();
	l.d2();
	return 0;
}
