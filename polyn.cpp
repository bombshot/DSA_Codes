
#include<iostream>
#include<math.h>
using namespace std;

struct Term
{
	int coeff;
	int exp;
};

class Poly
{
	Term *p;
	int n;

public:

	Poly(int t);
	friend istream& operator >> (istream &cin, Poly &P);
	friend ostream& operator <<(ostream &cout, Poly &P);
	Poly operator +(Poly p2);
	Poly operator *(Poly p2);
	int evaluate(int x);
	
};

Poly::Poly(int t)
	{
		n=t;
		p= new Term[n];
		for(int i=0;i<n;i++)
			p[i].coeff=0;

	}

istream& operator>>(istream &cin, Poly &P)
	{
		for(int i=0;i<P.n;i++)
		{
			cin>>P.p[i].coeff>>P.p[i].exp;
		}
		return cin;
	}
	
ostream& operator<<(ostream &cout, Poly &P)
	{
		for(int i=0;i<P.n;i++)
		{
			if(P.p[i].coeff==0)
				break;
			if(P.p[i].coeff>0)
				cout<<"+"<<P.p[i].coeff<<"x^"<<P.p[i].exp<<" ";
			else
				cout<<P.p[i].coeff<<"x^"<<P.p[i].exp<<" ";

		}
		return cout;
	}
	
Poly Poly::operator +(Poly p2)
	{
		Poly p_temp(n+p2.n);
		int i=0,j=0,k=0;

		while(i<n && j<p2.n)
		{
			if(p[i].exp == p2.p[j].exp)
			{
				p_temp.p[k].exp=p[i].exp;
				p_temp.p[k++].coeff = p[i++].coeff + p2.p[j++].coeff;
			}
			else if(p[i].exp > p2.p[j].exp)
			{
				p_temp.p[k].exp = p[i].exp;
				p_temp.p[k++].coeff = p[i++].coeff;
			
			}
			else
			{
				p_temp.p[k].exp = p2.p[j].exp;
				p_temp.p[k++].coeff = p2.p[j++].coeff;
				
			}
		}

		while(i<n)
		{
			p_temp.p[k].exp = p[i].exp;
			p_temp.p[k++].coeff = p[i++].coeff;
		}

		while(j<p2.n)
		{
			p_temp.p[k].exp = p2.p[j].exp;
			p_temp.p[k++].coeff = p2.p[j++].coeff;
		
		}

		return p_temp;

	}


Poly Poly::operator *(Poly p2)
	{
		Poly p_temp(n*p2.n);
		int i=0,j=0,k=0;

		for(i=0;i<n;i++)
		{
			for(j=0;j<p2.n;j++)
			{
				p_temp.p[k].coeff = p[i].coeff * p2.p[j].coeff;
				p_temp.p[k++].exp = p[i].exp + p2.p[j].exp;
			}
		}

		int c=0;
		int m;
		int flag;
		Poly p_temp_2(k);

		for(i=0;i<k;)
		{
			flag=0;
			p_temp_2.p[c].exp = p_temp.p[i].exp;
			p_temp_2.p[c].coeff = p_temp.p[i].coeff;

			for(j=i+1;j<k;j++)
			{

				if(p_temp_2.p[c].exp == p_temp.p[j].exp)
				{
					p_temp_2.p[c].coeff +=  p_temp.p[j].coeff;
					flag=1;
					m=j;
				}
			}

			if(flag==1)
				i=++m;
			else
				i++;
			c++;
		}
		return p_temp_2;

	}
	
int Poly::evaluate(int x)
	{
		int value=0;

		for(int i=0;i<n;i++)
		{
			value+= p[i].coeff* pow(x,p[i].exp);
		}
		return value;
	}

int main()
{
	int n1,n2;
	int cs;
	char ch;

	cout<<"Enter the no of terms in the Polynomial 1 : ";
	cin>>n1;
	Poly p1(n1);

	cout<<"Enter the no of terms in the Polynomial 2 : ";
	cin>>n2;
	Poly p2(n2);

	cout<<"\nEnter Coefficients and Exponents of Polynomial 1 :\n";
	cin>>p1;

	cout<<"\nEnter Coefficients and Exponents of Polynomial 2 : \n";
	cin>>p2;

	Poly p3(n1+n2);
	Poly p4(n1*n2);

	do
	{
		cout<<"1.Addition of Two Polynomials\n2.Multiplication of Two Polynomials\n3.Evaluation of a Polynomial\nEnter your choice : ";
		cin>>cs;
		cout<<"\nPolynomial 1 : ";
				cout<<p1;
		cout<<"\nPolynomial 2 : ";
				cout<<p2;
		switch(cs)
		{
		case 1: p3=p1+p2;
			cout<<"\nADDITION : "<<p3;
			break;

		case 2:	p4=p1*p2;
			cout<<"\nMULTIPLICATION : "<<p4;
			break;

		case 3 :int x;
			cout<<"\nEnter the value for which to evaluate the polynomial : ";
			cin>>x;
			cout<<"\nEvaluation of polynomial 1 : "<<p1.evaluate(x);
			cout<<"\nEvaluation of polynomial 2 : "<<p2.evaluate(x);
			break;
		default: cout<<"Invalid Choice!!!";
			break;
		}
		cout<<"\nDo you want to continue ? (Y/N)";
		cin>>ch;

	}	while(ch=='Y'||ch=='y');



	return 0;

}



