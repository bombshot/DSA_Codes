#include<bits/stdc++.h>
using namespace std;

class stacks {
    	char s[100];
    	int top;
    
  public:
  
    	stacks(): top(-1) {
    	}
    	void push(char );
    	void pop();
    	int empty();
    	char gettop() {
    		return s[top];
    	}
    
};


void stacks:: push(char c) {
	top++;
	s[top]=c;
}

void stacks:: pop() {
	top--;
}

int stacks:: empty() {
    	if(top==-1)
    		return 1;
    	return 0;
}

class expression {
	
	char a[100];
	
    public:
    
	expression() {
		cout<<"Enter the Expression : ";
		cin>>a;
	}
	void balance();
	int check(char,char );
	
};


int expression::check(char c,char top) {

	if(c==']') {
		if(top=='[')
		return 0;
	}
	
	else if(c==')') {
		if(top=='(')
		return 0;
	}
	
	else if(c=='}') {
		if(top=='{')
		return 0;
	}
	
	return 1;

}

void expression::balance() {
	int f=0;
	stacks s;
	
	for(int i=0;i<strlen(a);i++)	{
		if(a[i]=='('||a[i]=='['||a[i]=='{')
		s.push(a[i]);
	
		else {
			if(s.empty()) {
				f=1;
				break;
			}
			f=check(a[i],s.gettop());
			if(f==1)
			break;
			s.pop();
		
		}
	}

	if(s.empty()) {
		
		if(f==0) {
			cout<<"\nBalanced Expression\n\n";
			return;
		}
	}

	cout<<"\nNot a Balanced Expression\n\n";
}

int main(){
    
    	expression e;
    	e.balance();
       
    return 0;
}

