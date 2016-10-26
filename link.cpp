#include<iostream>
#include<string.h>
using namespace std;

class Stud {
	int prn;
	char name[50];
	Stud *next;
	Stud *head;
    public:
    	Stud():prn(0),next(NULL),head(NULL){
    	}
    	void insert(int , char* ,int );
    	void display();
    	int total_stud();
    	void remove(int );
    	void reverse(Stud*);
    	void merge();
    	Stud* rhead();
}; 


void Stud::insert(int p, char *n, int pos) {
	Stud* temp = new Stud;
	temp->prn = p;
	strcpy(temp->name , n);
	if(pos==0) {
		temp->next=head;
		head=temp;
		return;
	}
	Stud* t=head;
	for(int i=1;i<pos-1;i++) {
		t=t->next;
	}
	temp->next = t->next;
	t->next = temp;
}


void Stud::display() {
	Stud* temp = head;
	if(head==NULL){
		cout<<"\tList is empty!!\n";
		return ;
	} 
	cout<<"President :\t"<<temp->prn<<"\t"<<temp->name<<"\n\n";
	
	temp=temp->next;
	cout<<"Members : ";
	while(temp!=NULL) {
			if(temp->next==NULL)
			cout<<"\nSecretary :\t"<<temp->prn<<"\t"<<temp->name<<"\n";
			else
		cout<<" \t"<<temp->prn<<"\t"<<temp->name<<"\n\t";
		temp=temp->next;
	}
	
}


Stud* Stud::rhead() {
	return head;
}


int Stud::total_stud() {
	Stud* temp = head;
	int k=0;
	while(temp!=NULL) {
		k++;
		temp=temp->next;
	}
	return k;
}


void Stud::remove(int p) {
	Stud* temp = head;
	if(head->prn==p) {
		head=temp->next;
		delete temp;
		return;
	}
	while(temp->next->prn!=p) {
		temp=temp->next;
	}
	Stud* t=temp->next;
	temp->next=t->next;
	delete t;
}


void Stud::reverse(Stud*s) {
	if(s==NULL)
		return;
	reverse(s->next);
	cout<<s->prn<<"\t"<<s->name<<"\n";
}


void Stud::merge() {
	int p,x;
	Stud s1;
	char n[50];
	cout<<"Enter the PRN and Name of President : ";
	cin>>p>>n;
	s1.insert(p,n,0);
	cout<<"Enter the PRN and Name of Secretary : ";
	cin>>p>>n;
	s1.insert(p,n,1);
	cout<<"Enter the no of members : ";
	cin>>x;
	
	for(int i=2;i<x+2;i++){
		cout<<"Enter the PRN and Name of the members :";
		cin>>p>>n;
		s1.insert(p,n,i);
	}
	
	Stud* temp=head;
	while(temp->next!=NULL) 
		temp=temp->next;
		
	temp->next=s1.head;
	s1.head=NULL;
}


int main() {	
	Stud s;
	char ch,n[50];
	int c,p,pos,x;
	cout<<"Enter the PRN and Name of President : ";
	cin>>p>>n;
	s.insert(p,n,0);
	cout<<"Enter the PRN and Name of Secretary : ";
	cin>>p>>n;
	s.insert(p,n,1);
	do{
		cout<<"\n1.Add\n2.Display\n3.Remove\n4.Reverse\n5.No. of Students\n6.Merge another list\nEnter your choice : ";
		cin>>c;
		switch(c) {
			case 1:	cout<<"Enter the PRN and Name of the member : ";
				cin>>p>>n;
				s.insert(p,n,s.total_stud());
				break;
			case 2: cout<<"The Details are as follows :-\n\t\tPRN\tName\n";
				//cout<<s.total_stud();
				s.display(); 
				break;
			case 3: cout<<"Enter the PNR of student to delete : ";
				cin>>p;
				s.remove(p);
				break; 
			case 4: cout<<"\nReverse : \nPRN\tName\n";
				s.reverse(s.rhead()); 
				break;
			case 5: cout<<"Total no of students in the  list : "<<s.total_stud();
				break;
			case 6: s.merge();
				break;
			
			default: cout<<"Invalid choice!!!!";
				break;
		}
		cout<<"\nDo you want to continue (y/n) : ";
		cin>>ch;
		
	}while(ch=='y'||ch=='Y');		
}










