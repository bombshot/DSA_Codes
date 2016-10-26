#include<iostream>
using namespace std;

class SparceMatrix {
	int r,c,k;
	int a[50][3];
    public:
    	void getsparce();
    	void add(SparceMatrix );
    	void transpose();
    	void fasttranspose();
    	void display();
    	
};

void SparceMatrix::getsparce() {
	cout<<"Enter the row and column of the matrix : ";
	cin>>r>>c;
	a[0][0]=r;
	a[0][1]=c;
	k=1;
	int x;
	cout<<"Enter the matrix : \n";
	for(int i=1; i<=r; i++) {
		for(int j=0; j<c; j++) {
			cin>>x;
			if(x!=0) {
				a[k][0]=i-1;
				a[k][1]=j;
				a[k++][2]=x;
			}
		}
	}
	a[0][2]=k-1;
}



void SparceMatrix::add(SparceMatrix p) {
	SparceMatrix d;
	int m=k;int n=p.k;int l=1;
	int i=1,j=1;
	while(i<m && j<n) {
		if(a[i][0] < p.a[j][0]) {
			d.a[l][0]=a[i][0];
			d.a[l][1]=a[i][1];
			d.a[l++][2]=a[i++][2];
		}
		else if(a[i][0] > p.a[j][0]) {
			d.a[l][0]=p.a[j][0];
			d.a[l][1]=p.a[j][1];
			d.a[l++][2]=p.a[j++][2];
		}
		else {
			if(a[i][1]==p.a[j][1]) {
				d.a[l][0]=a[i][0];
				d.a[l][1]=a[i][1];
				d.a[l++][2]=a[i++][2]+p.a[j++][2];
			}
			else if(a[i][1] < p.a[j][1]) {
				d.a[l][0]=a[i][0];
				d.a[l][1]=a[i][1];
				d.a[l++][2]=a[i++][2];
			}
			else {
				d.a[l][0]=p.a[j][0];
				d.a[l][1]=p.a[j][1];
				d.a[l++][2]=p.a[j++][2];
			}
		}
	}
	while(i<m)
	{	d.a[l][0]=a[i][0];
		d.a[l][1]=a[i][1];
		d.a[l++][2]=a[i++][2];
	}
	while(j<n) {
		d.a[l][0]=p.a[j][0];
		d.a[l][1]=p.a[j][1];
		d.a[l++][2]=p.a[j++][2];
	}
	d.k=l;
	d.a[0][0]=r;
	d.a[0][1]=c;
	d.a[0][2]=l-1;
	d.display();
}


void SparceMatrix::transpose() {
	SparceMatrix d;
	int l=1;
	for(int i=0;i<=c;i++)
		for(int j=1;j<=a[0][2];j++) {
			if(a[j][1]==i) {
				d.a[l][0]=i;
				d.a[l][1]=a[j][0];
				d.a[l++][2]=a[j][2];
			}
		}
	d.k=l;
	d.a[0][0]=c;
	d.a[0][1]=r;
	d.a[0][2]=l-1;	
	d.display();
}

void SparceMatrix::fasttranspose() {
	SparceMatrix d;
	int x[50]={0},y[50]={0};
	for(int i=1;i<k;i++) {
		x[a[i][1]]++;		
	}
	y[0]=1;
	for(int i=1;i<=c;i++) {
		y[i]=y[i-1]+x[i-1];
	}
	for(int i=1;i<k;i++) {
		d.a[y[a[i][1]]][0]=a[i][1];
		d.a[y[a[i][1]]][1]=a[i][0];
		d.a[y[a[i][1]]][2]=a[i][2];
		y[a[i][1]]++;
	}d.k=k;
	d.a[0][0]=c;
	d.a[0][1]=r;
	d.a[0][2]=k-1;
	d.display();
}

void SparceMatrix::display() {
	cout<<"\n";
	for(int i=0; i<k; i++) {
		for(int j=0; j<3; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}


int main() {
	SparceMatrix s,t;
	int ch;
	char c;
	s.getsparce();
	do {
		cout<<"1.Display the sparce matrix \n2.Transpose of the matrix \n3.Addition of two sparce matrix\n4.Fast Transpose\nEnter the choice : ";
		cin>>ch;
		switch(ch) {
			case 1: cout<<"\nSparce Matrix is : ";
				s.display();
				break;
			case 2: cout<<"\nTranspose of the matrix : ";
				s.transpose();
				break;
			case 3: t.getsparce();
				cout<<"\nAddition of Matrices : ";
				s.add(t);
				break;
			case 4: cout<<"\nFast Transpose : ";
				s.fasttranspose();
				break;
				
			default:cout<<"Invalid Choice !!!\n";
			
		}
	cout<<"Do you want to continue (y/n) : ";
			cin>>c;
	}while(c=='y'||c=='Y');

	
}












