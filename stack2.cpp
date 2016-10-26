#include<iostream>
#include<string.h>

using namespace std;
class Convert
{
public:
    void intpr();
    void prtin();
    void potin();
    void potpr();
    void prtpo();
};
bool hpre(char a,char b)
{
    if(a=='^')
       return true;
    else if(a=='*'||a=='/')
       return true;
    else if(b=='(')
       return false;
    else
        return false;
}

void Convert::intpr()
{
    cout<<"Enter input : ";
    char st[20]={'\0'};
    char s[20],r[20]={'\0'};
    cin>>s;
    int i,k,top=-1;
    if(St.check(s))
    {   for(i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]==')')
            {  while(st[top]!=')')
               {   
                   for(k=strlen(r);k>0;k--)
                   r[k]=r[k-1];
                   r[0]=st[top--];
               }
               top--;
            }   
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='(')
            {
                while(k>-1&&hpre(st[top],s[i]))
                {
                   for(k=strlen(r);k>0;k--)
                   r[k]=r[k-1];
                   r[0]=st[top--];
                }
                st[++top]=s[i];
            }
            else
            {
                  for(k=strlen(r);k>0;k--)
                  r[k]=r[k-1];
                  r[0]=s[i];
            }
        }
        while(top>-1)
        {
            for(k=strlen(r);k>0;k--)
            r[k]=r[k-1];
            r[0]=st[top--];
        }
        cout<<"Prefix      : "<<r<<"\n";
    }	
    else
    {   
    	cout<<"\nUnbalanced expression";
    }
}

void Convert::prtin()
{
    cout<<"Enter input : ";
    char st[20]={'\0'};
    char s[20],r[20]={'\0'};
    int x=0,i,top=1;
    cin>>s;
    if(St.check(s))
    { 
        for(i=0;i<strlen(s);i++)
    	{
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
                st[++top]=s[i];
            else
            {
                r[x++]=s[i];
            	if(top>-1)
              	{
               	    r[x++]=st[top--];
            	}
            }
    	}
        cout<<"Infix       : "<<r<<"\n";
    }
}

void Convert::potin()
{
    char st[20]={'\0'};
    char s[20],r[20]={'\0'};
    int i,j,top=-1;
    cout<<"Enter input : ";
    cin>>s;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
            st[++top]=s[i];
        else if(top>-1)
        {
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            r[0]=st[top--];
            r[1]=s[i];
        }
        else
        {
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            r[0]=s[i];
        }
    }
    cout<<"Infix       : "<<r<<"\n";
}

void Convert::potpr()
{
    char st[20]={'\0'};
    char s[20],r[20]={'\0'};
    int i,j,top=-1;
    cout<<"Enter input : ";
    cin>>s;
    for(i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
            st[++top]=s[i];
        else if(!(s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='^'))
        {
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            r[0]=st[top--];
            r[1]=s[i-1];
            r[2]=s[i];
            i--;
        }
        else
        {
            for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
            r[0]=s[i];
        }
    }
    while(top>-1)
    {
        for(j=strlen(r);j>0;j--)
                r[j]=r[j-1];
        r[0]=st[top--];
    }
    cout<<"Prefix      : "<<r<<"\n";
}

void Convert::prtpo()
{
    char st[20][20];
    char s[20]={'\0'},a[20],b[20],r[20];
    cout<<"Enter input : ";
    cin>>s;
    int i,top;
    top=-1;
    for(i=strlen(s)-1;i>=0;i--)
    {
        r[0]=s[i];
        r[1]='\0';
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^')
        {
            strcpy(a,st[top--]);
            strcpy(b,st[top]);
            strcat(a,r);
            strcat(a,b);
            strcpy(st[top],a);
        }
        else
        {
            strcpy(st[++top],r);
        }
    }
    cout<<"Postfix     : "<<st[top]<<"\n";
}

int main()
{
    int ch,cnt=1;
    Convert o;
    cout<<"1.Infix to prefix \n2.Prefix to infix \n3.Postfix to infix \n4.Postfix to prefix \n5.Prefix to postfix";
    while(cnt==1)
    {
        cout<<"\nEnter your choice : ";
        cin>>ch;
        if(ch==1)
           o.intpr();
        else if(ch==2)
           o.prtin();
        else if(ch==3)
           o.potin();
        else if(ch==4)
           o.potpr();
        else
           o.prtpo();
        cout<<"\nWant to continue(0/1) : ";
        cin>>cnt;
    }
    return 0;
}
