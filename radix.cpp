#include<iostream>
using namespace std;
int a[100];
void cnt(int a[],int n,int k) {
    int o[n+1];
    int c[10]={0};

    for(int i=0;i<n;i++) {
        c[(a[i]/k)%10]++;
    }
    for(int i=1;i<10;i++) {
        c[i]+=c[i-1];
    }
    for(int i=n-1;i>=0;i--) {
        o[c[(a[i]/k)%10]-1]=a[i];
        c[(a[i]/k)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=o[i];
}

void radix_sort(int a[],int n) {
    int max=0;
    for(int i=0;i<n;i++) {
        if(a[i]>max)
            max=a[i];
    }
    	for (int i= 1; max/i > 0; i*= 10)
		cnt(a, n, i);

}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    radix_sort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
