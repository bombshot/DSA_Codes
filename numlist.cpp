#include<iostream>
using namespace std;

class List {
	int data;
	List *next;
	List *head;
    public:
    	List():data(0),next(NULL),head(NULL){
    	}
    	void insert(int );
    	void display();
    	void remove();
    	List seprate(List &);
}; 


void List::insert(int p) {
	List* temp = new List;
	temp->data = p;
	temp->next = head;
	head = temp;
}

void List::remove() {
	List* temp = head;
	if(head==NULL) {
		cout<<"List is empty!!!\n";
		return;
	}
	while(temp->next!=NULL) {
		if(temp->next->data<0) {
			List* t=temp->next;
			temp->next=t->next;
			delete t;
		}
		else
			temp=temp->next;
		if(temp==NULL)
			break;
	}	
	
	if(head->data<0) {
		temp=head;
		head=temp->next;
		delete temp;
	}
}


void List::display() {
	List* temp = head;
	if(head==NULL){
		cout<<"\tList is empty!!\n";
		return ;
	}
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	
}

List List::seprate(List &l) {
	List* temp=head;
	List _l;
	while(temp!=NULL) {
		if(temp->data<0) {
			_l.insert(temp->data);
		}
		else
			l.insert(temp->data);
		temp=temp->next;	
	}
	return _l;
}

int main() {
	List l;
	int ch,x;
	char c;
	do {	List l1,l2;
		cout<<"\n1.Insert\n2.Delete the negative no\n3.Seprate the positive and negative no\n4.Display\nEnter your choice : ";
		cin>>ch;
		switch(ch) {
			case 1: cout<<"Enter the no : ";
				cin>>x;
				l.insert(x);
				break;
			case 2: l.remove();
				break;
			case 3: l1=l.seprate(l2);
				cout<<"\nList of negative numbers : ";
				l1.display();
				cout<<"\nList of positive numbers : ";
				l2.display();
				break;
			case 4: l.display();
				break;
			default: cout<<"Invalid Choice!!!!\n";
		}
		cout<<"\nDo you want to continue(y/n) : ";
		cin>>c;
	} while(c=='y'||c=='Y');
}










