#include<iostream>
using namespace std;

int partition(int a[],int l,int h) {
    int p=h;
    int j=l;
    for(int i=l;i<=h-1;i++) {
        if(a[i]<=a[p]) {
            swap(a[j],a[i]);
            j++;
        }
    }
    swap(a[p],a[j]);
    return j;
}


void quick_sort(int a[],int l, int h) {
    if(l<h) {
    int p=partition(a,l,h);
    quick_sort(a,l,p-1);
    quick_sort(a,p+1,h);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
