#include<iostream>
#define SIZE 100;
using namespace std;

int main()
{
  int n,i;
  float a[SIZE];
  
  cout<<"\n ENTER THE NO OF STUDENT";
  cin>>n;
  
  
  cout<<"\n ENTER THE MARKS OF N STUDENT";
  for(i=0;i<n;i++)
  {
     cin>>a[i];
     
   }
   
   
   quicksort(a,n);
   
   display(a,n);
   return 0;
 }
   
   
   int part(float a[],int x,int y){
    int i,j,t;
    j=y+1 ;
    t=a[x];
    i=x;
    do{
        do{
            i++;
        }while(a[i]<t&&i<y);
        do{
            j--;
        }while(a[j]>t&&j>=x);
        if(i<j){
            swap(a[i],a[j]);
        }
    }while(i<j);
    a[x]=a[j];
    a[j]=t;
    return j;
}
void quicksort(float a[],int x,int y{
    int j;
    if(x<y){
        j=part(a,x,y);
        quicksort(a,x,j-1);
        quicksort(a,j+1,y);
    }
}


void display(float a[],int n)
{
   int i;
    for(i=0;i<n;i++)
    {
     cout<<" ";
    }
    
 }    
