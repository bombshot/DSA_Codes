#include<iostream>
using namespace std;

class List {
	int data;
	List* next;
	List* prev;
	List* head;
     public:
     	List(): data(0),next(NULL),prev(NULL),head(NULL) {
     	}
     	void push_front(int x);
     	void pop_front();
     	void merge(List &);
     	int empty();
     	void display();
};

void List::push_front(int x) {
	List* temp=new List;
	temp->data=x;
	temp->next=head;
	if(head!=NULL)
		head->prev=temp;
	head=temp;
}

void List::pop_front() {
	List* temp=head;
	head=temp->next;
	if(head!=NULL)
		head->prev=NULL;
	
	delete temp;
}

int List::empty() {
	if(head==NULL)
		return 1;
	else
		return 0;
}

void List::merge(List &_l) {
	List l;
	while(!empty() && !_l.empty()) {
		if(head->data > _l.head->data) {
			l.push_front(head->data);
			pop_front();
		}
		else {
			l.push_front(_l.head->data);
			_l.pop_front();
		}
		
	}
	while(!empty()) {
		l.push_front(head->data);
			pop_front();
	}
	while(!_l.empty()) {
		l.push_front(_l.head->data);
			_l.pop_front();
	}
	
	cout<<endl;
	l.display();
}

void List::display() {
	List *temp=head;
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}


int main() {
	List l1,l2;
	int n1,n2,x;
	char ch;
	do {
		cout<<"Enter the no of elements in list 1: ";
		cin>>n1;
	
		cout<<"Enter the elements : ";
		for(int i=0;i<n1;i++) {
			cin>>x;
			l1.push_front(x);
		}
	
		cout<<"Enter the no of elements in List 2: ";
		cin>>n2;
	
		cout<<"Enter the elements : ";
		for(int i=0;i<n2;i++) {
			cin>>x;
			l2.push_front(x);
		}
		cout<<"\nThe Merged List is : ";
		l1.merge(l2);
		cout<<"\nWant to continue (y/n) : ";
		cin>>ch; 	
	
	} while(ch=='y'||ch=='Y');
}



