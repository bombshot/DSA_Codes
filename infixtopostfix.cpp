#include<iostream>
#include<string>
#include<math.h>
#include<stack>
using namespace std;
int prefer(char ch){
	if(ch=='+') return 1;
	if(ch=='-') return 2;
	if(ch=='*' || ch=='/') return 3;
	return 0;
}
int is_operand(char ch){
	if(ch!='+' && ch!='-' && ch!='*' && ch!='/' && ch!='(' && ch!=')') return 1;
	return 0;
}
int is_operator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/') return 1;
	return 0;
}
int arith(int a,int s,char c){
	if(c=='+') return a+s;
	if(c=='-') return a-s;
	if(c=='*') return a*s;
	if(c=='/') return a/s;
}
string postfix(string s){
	stack<char>s1;
	string res="";
	for(int i=0;s[i];i++){
		if(is_operator(s[i])){
			while(s1.size() > 0 && prefer(s1.top()) >= prefer(s[i])){
				res+=s1.top();
				s1.pop();
			}
			s1.push(s[i]);
		}
		else if(is_operand(s[i])){
			res+=s[i];
		}
		else{
			if(s[i]=='(')
				s1.push(s[i]);
			else{
				while(s1.size()>0){
					if(s1.top()=='('){
						s1.pop();
						break;
					}
					res+=s1.top();
					s1.pop();
				}
			}
		}
		//cout<<res<<endl;
	}
	while(s1.size()>0){
        res+=s1.top();
        s1.pop();
	}
	return res;
}
int evaluate(string s){
	int ar[26]={0};
	for(int i=0;s[i];i++){
		if(is_operand(s[i])){
			ar[s[i]-'a']++;
		}
	}
	for(int i=0;i<26;i++){
		if(ar[i]){
			cout<<endl<<"enter the value of "<<(char)(i+97)<<endl;
			cin>>ar[i];
		}
	}
	stack<int>res;
	for(int i=0;s[i];i++){
		if(is_operand(s[i])){
			res.push(ar[s[i]-'a']);
		}
		else if(is_operator(s[i])){
            int t1,t2;
			char ch;
			ch=s[i];
			t1=res.top();
			res.pop();
			t2=res.top();
			res.pop();
			res.push(arith(t2,t1,ch));
		}
	}
	return res.top();
}
int main(){
	cout<<"......enter the infix expression....\n";
	string s;
	cin>>s;
	cout<<endl;
	string p=postfix(s);
	cout<<"postfix expression is"<<endl;
	cout<<p<<endl;
	do{
		cout<<endl<<"want to evaluate say y or any other character"<<endl;
		char c;
		cin>>c;
		if(c=='Y' || c=='y'){
			int res=evaluate(p);
			cout<<endl<<"result is"<<endl;
			cout<<res<<endl;
		}
		else{
			break;
		}
	}while(1);
	return 0;
}
