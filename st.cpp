#include<iostream>
#include<string.h>
using namespace std;

class Stack {
	int top;
	char s[100];
    public:
    	Stack():top(-1) {
    	}
    	void push(char );
    	void pop();
    	bool isempty();
    	int rtop();
    	int vtop();
};

void Stack::push(char c) {
	s[++top]=c;
}

void Stack::pop() {
	--top;
}

bool Stack::isempty() {
	if(top==-1)
		return true;
	return false;
}
int Stack::vtop() {
	return top;
}

int Stack::rtop() {
	
	return s[top];
}

int prt(char c) {
	if(c=='^')
		return 4;
	if(c=='*'||c=='/')
		return 3;
	if(c=='+'||c=='-')
		return 2;
	
}


void intopost() {
	Stack st;
	char s[100],t[100]={'\n'};
	int k=0;
	cin>>s;
	for(int i=0; i<strlen(s); i++ ) {
	
		/*if(s[i]=='(') {
			st.push(s[i]);
		}
		else if(s[i]==')') {
			 char x=st.rtop();
			 st.pop();
                        while(x!='(')
                        {
                                t[k++]=x;
                                x=st.rtop();
			 	st.pop();
                        }
		}*/
	
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
			if(st.vtop()==-1)
				st.push(s[i]);
			else{
				if(prt(s[i])>prt(st.rtop()))
					st.push(s[i]);
				else {	
					while(prt(s[i])<=prt(st.rtop())) {
					t[k++]=st.rtop();
					st.pop();
					}
					st.push(s[i]);
				}
			}
		}
		
		else
			t[k++]=s[i];
	}
	while(!st.isempty()) {
		t[k++]=st.rtop();
		st.pop();
	}
	cout<<"Postfix expression : "<<t;
	
}


int main() {
	intopost();
}

