#include<iostream>
using namespace std;

int part(float a[],int l,int u){
    int i,j,t;
    j=u+1 ;
    t=a[l];
    i=l;
    do{
        do{
            i++;
        }while(a[i]<t&&i<u);
        do{
            j--;
        }while(a[j]>t&&j>=l);
        if(i<j){
            swap(a[i],a[j]);
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=t;
    return j;
}
void quicksort(float a[],int l,int u){
    int j;
    if(l<u){
        j=part(a,l,u);
        quicksort(a,l,j-1);
        quicksort(a,j+1,u);
    }
}
void selection(float a[],int n){
	int k;
	for(int i=0;i<n-1;i++){
		k=i;
		float c=a[i];
		for(int j=i+1;j<n;j++){
			if(a[j]<c){
				c=a[j];
				k=j;
			}
		}
		if(k!=i){
			float t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
	cout<<"selection sort"<<"\n";
	for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	cout<<"\n";
}
void bubble(float b[],int n){
	float t;
	for(int i=1;i<n;i++){
		for(int j=0;j<(n-i);j++){
			if(b[j]>b[j+1]){
			    t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	cout<<"bubble sort"<<"\n";
	for(int i=0;i<n;i++)
    	cout<<b[i]<<" ";
	cout<<"\n";
}
void insertion(float arr[],int n){
	int j,i;
	for(i=1;i<n;i++){
		float c=arr[i];
		for(j=i-1;j>=0&&c<arr[j];j--)
		arr[j+1]=arr[j];
		arr[j+1]=c;
	}
	cout<<"\n";
	cout<<"insertion sort"<<"\n";
	for(i=0;i<n;i++)
    	cout<<arr[i]<<" ";
	cout<<"\n";
}
void shellsort(float arr[],int n){
	int g,i,j;
	g=n/2;
    while(g>0){
    	for(i=gap;i<n;i++){
    		float c=arr[i];
    		for(j=i;j>=gap&&arr[j-gap]>c;j=j-g)
    		arr[j]=arr[j-g];
    		arr[j]=c;
		}
		g=g/2;
	}
	cout<<"\n";
	cout<<"shell sort"<<"\n";
	for(i=0;i<n;i++)
    	cout<<arr[i]<<" ";
	cout<<"\n";
}
int main()
{
   char ch;
   float arr[100],a[100],b[100],d[100],m[100],e[100];
   int i,n,t;
   cout<<"enter n"<<"\n";
   cin>>n;
   cout<<"enter the percentages"<<"\n";
   for(i=0;i<n;i++)
        cin>>arr[i];
   for(i=0;i<n;i++)
        e[i]=a[i]=b[i]=d[i]=m[i]=arr[i];
	do{
        cout<<"enter"<<endl;
        cout<<"1.selection sort"<<endl;
        cout<<"2.bubble sort"<<endl;
        cout<<"3.insertion sort"<<endl ;
        cout<<"4.shell sort"<<endl ;
        cout<<"5.quicksort" << endl ;
        cin>>t;
        switch(t){
            case 1:selection(a,n);break;.
            case 2:bubble(b,n);break;
            case 3:insertion(d,n);break;
            case 4:shellsort(m,n);break;
            case 5:quicksort(e,0,n);break;
            default: cout<<"wrong value entered\n";
         }    
         cout<<"\n enter y/n to continue or not"<<"\n";
         cin>>ch;
         }while(ch=='y'||ch=='Y');
}   
