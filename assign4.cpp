#include<bits/stdc++.h>

using namespace std;
int k=0;
struct stud
{	
	int prn,month,day;

	void get();
	void display();
	void merge(int na,int nb,stud d[],stud d1[],stud d2[]);
	
};

void stud::get()
{	int f=0;
	cin>>prn>>day>>month;
	if(month>12)
		f=1;
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{	if(day>31)
		f=1;
	}
	if(month==2&&day>28)
	{	f=1;
	}
	if(month==4||month==6||month==9||month==11)
	{	if(day>30)
		f=1;
	}
	if(f==1)
	{	cout<<"Invalid date!!!";
		exit(0);
	}
}

void stud::merge(int na,int nb,stud d[],stud d1[],stud d2[])
{	int s=0,t=0;
	while(s<na&&t<nb)
	{	if(d1[s].month<d2[t].month)
			d[k++]=d1[s++];
		else if(d1[s].month>d2[t].month)
			d[k++]=d2[t++];
		else
		{	if(d1[s].day<d2[t].day)
			d[k++]=d1[s++];
		else
			d[k++]=d2[t++];
		}
	}

	if(s>=na&&t<nb)
	{	for(int i=t;i<nb;i++)
			d[k++]=d2[i];
	}

	else if(s<na&&t>=nb)
	{	for(int i=s;i<na;i++)
			d[k++]=d1[i];
	}
}

void stud::display()
{	cout<<"\n"<<prn<<"\t"<<day<<"\t"<<month;
}


int main()
{	stud d1[100],d2[100],d[100],s;
		
	int na,nb;
	cout<<"Enter the no of students in div1 :";
	cin>>na;
	cout<<"Enter the details of students (prn day month):\n";
	for(int i=0;i<na;i++)
		d1[i].get();
	

	cout<<"Enter the no of students in div2 :";
	cin>>nb;
	cout<<"Enter the details of students (prn day month):\n";

	for(int i=0;i<nb;i++)
		d2[i].get();

	
	s.merge(na,nb,d,d1,d2);
	cout<<"\nPRN\tDAY\tMONTH";

	for(int i=0;i<k;i++)
		d[i].display();

	return 0;
}
	
