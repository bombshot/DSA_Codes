#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class poly{
	char s[20];
	int exp[20],cof[20],n,er[20],cr[20];

public:
    void opr();
    friend void operator>>(istream &cin,poly &p)
    {
        cin>>p.s;
    }
    friend void operator<<(ostream &cout,poly &p)
    {
    	int i;
    	for(i=0;i<p.n;i++)
    	    cout<<p.cr[i]<<"(x^"<<p.er[i]<<")+";
    }
    void pw(int);
    void add(poly);
    void mul(poly,poly&);
};

void poly::opr()
{
    int i,cnt=0;
    int x=0;
    for(i=0;i<strlen(s);i++)
        if(s[i]>='0'&&s[i]<='9')
        {
            while(s[i]>='0'&&s[i]<='9')
            {
                x=x*10+s[i]-48;
                i++;
            }
            cof[cnt]=x;
            x=0;
            while(!(s[i]>='0'&&s[i]<='9'))
                  i++;
            while(s[i]>='0'&&s[i]<='9')
            {
                x=x*10+s[i]-48;
                i++;
            }
            exp[cnt]=x;
            x=0;
            cnt++;
         }
    n=cnt;
}

void poly::pw(int x)
{
    int cnt=0,i;
    for(i=0;i<n;i++)
        cnt=cnt+cof[i]*pow(x,exp[i]);
    cout<<cnt<<"\n";
}

void poly::add(poly p2)
{
    int x,y;
	cout<<"\n"<<"Addition of polynomials : ";
    for(x=0,y=0;x<n&&y<p2.n;)
    {
        if(exp[x]==p2.exp[y])
        {
            cout<<cof[x]+p2.cof[y]<<"(x^"<<exp[x]<<")+";
            x++;
            y++;
        }
        else if(exp[x]>p2.exp[y])
        {
            cout<<cof[x]<<"(x^"<<exp[x]<<")+";
            ++x;
        }
        else
        {
            cout<<p2.cof[y]<<"(x^"<<p2.exp[y]<<")+";
            ++y;
        }
    }
    if(x==n&&y<p2.n)
        while(y<p2.n)
        {
            cout<<p2.cof[y]<<"(x^"<<p2.exp[y]<<")+";
            ++y;
        }
    else if(y==p2.n&&x<n)
        while(x<n)
        {
            cout<<cof[x]<<"(x^"<<exp[x]<<")+";
            ++x;
        }
   cout<<"0";
}
void poly::mul(poly p2,poly &p3)
{
    cout<<"\n"<<"Multiplication : ";
    int cnt=0,x,y,i;
    for(x=0;x<n;x++)
        for(y=0;y<p2.n;y++)
    {
        p3.er[cnt]=exp[x]+p2.exp[y];
        p3.cr[cnt]=cof[x]*p2.cof[y];
        cnt++;
    }
    for(x=0;x<cnt;x++)
        for(y=x+1;y<cnt;y++)
    {
        if(p3.er[x]==p3.er[y])
        {
        	p3.cr[x]+=p3.cr[y];
            i=y;
            while(i<cnt-1)
            {
            	p3.er[i]=p3.er[i+1];
            	p3.cr[i]=p3.cr[i+1];
            }
            cnt--;
        }
    }
    for(x=0;x<cnt;x++)
        for(y=0;y<cnt-x-1;y++)
    {
        if(p3.er[y]<p3.er[y+1])
        {
            i=p3.er[y];
            p3.er[y]=p3.er[y+1];
            p3.er[y+1]=i;
            i=p3.cr[y];
            p3.cr[y]=p3.cr[y+1];
            p3.cr[y+1]=i;
        }
    }
    p3.n=cnt;
}
int main()
{
    int x1,x2;
    poly p1,p2,p3;
    cout<<"Enter 1st polynomial : ";
    cin>>p1;
    cout<<"Enter 2nd polynomial : ";
    cin>>p2;

    p1.opr();
    p2.opr();
    cout<<"Enter value of x for p1&p2 : ";
    cin>>x1>>x2;
    cout<<"\n"<<"Value at x p1 : ";
    p1.pw(x1);
    cout<<"\n"<<"Value at x p2 : ";
    p2.pw(x2);
    p1.add(p2);
    cout<<"\n";
    p1.mul(p2,p3);
    cout<<p3;
    cout<<"0";
    return 0;
}
