#include<bits/stdc++.h>

#define max 5
using namespace std;


class orders
{
  
  int data[5];
  int front,rear;
    	public:
    		orders()
    		{
    			for(int i=0;i<5;i++)
    			data[i]=0;
			}
    	void initialise();
    	int empty();
    	int full();
    	void enque(int x);
    	int deque();
    	void display();
};

void orders::initialise()
{
	front=-1;
	rear=-1;
}

int orders::empty()
{
	if(rear==-1)
	return 1;
	return 0;
}

int orders::full()
{
	if((rear+1)%5==front)
	return 1;
	return 0;
}

void orders::enque(int x)
{
    if(empty())
	{
		rear=0;
		front=0;
		data[rear]=x;
	}
	else
	{
		rear=(rear+1)%5;
	data[rear]=x;
    }
}

int orders::deque()
{
	int x1;
	if(empty())
	{
		x1=-1;
		return x1;
	}
	x1=data[front];
	if(rear==front)
	{
		rear=-1;
		front=-1;
	}
	else
	 front=(front+1)%5;
	 
	 return x1;
}

void orders::display()
{
	cout<<"\n\tQueue looks like: ";
    int i=front;
    while(i!=rear)
    {
    	cout<<data[i]<<" ";
    	i=(i+1)%5;
	}
	cout<<data[rear];
}


int main()
{
	orders ob1;
	char ch='y';
	int op,x,x2;
	
	ob1.initialise();
	while(ch=='y'|| ch=='Y')
	{
		cout<<"\n\nEnter the option";
		cout<<"\n1.enque";
		cout<<"\n2.deque/display";
		cout<<"\n3.display";
		cin>>op;
		switch(op)
		{
			case 1:cout<<"\nadd a :";
			       cin>>x;
			       ob1.enque(x);
			       break;
			case 2:cout<<"\ndequed cost is:: ";       
			       x2=ob1.deque();
			       if(x2==-1)
			       cout<<"\nNO ORDERS...";
			       else
			       cout<<x2;
			       break;
			case 3:ob1.display();      
		}
		
		cout<<"\nDo you wanna repeat(y/n)";
		cin>>ch;		
	}
	
	
	
	
}

