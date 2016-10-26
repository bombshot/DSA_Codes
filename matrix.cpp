#include<iostream>
using namespace std;
class matrix
{
	int a[10][10],b[10][10],m;
	
	public:

	void get();
	void upper_triangle();
	void sum_diag();
	void transpose();
	void add();
	void sub();
	void mul();
	void saddle();
};

void matrix::get()
{	cout<<"Enter the order of matrix :";
	cin>>m;
	cout<<"Enter the matrix A:\n";
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	
	
	cout<<"Enter the matrix B:\n";
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			cin>>b[i][j];
	

}

void matrix::sum_diag()
{	int s=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
		{	if(i==j)
			s+=a[i][j];
		}
	cout<<s;
}

void matrix::upper_triangle()
{	int f=0;	
	for(int i=0;i<m;i++)
		for(int j=0;j<i;j++)
		{	if(a[i][j]!=0)
			{	cout<<"Matrix A is not a upper triangular matrix ";
				f=1;
				break;
			}
		}
	if(f==0)
		cout<<"Matrix A is upper triangular matrix";
			
}

void matrix::transpose()
{	for(int i=0;i<m;i++)
	{	for(int j=0;j<m;j++)
			cout<<a[j][i]<<" ";
		cout<<"\n";
	}
}

void matrix::add()
{	for(int i=0;i<m;i++)
	{	for(int j=0;j<m;j++)
			cout<<a[i][j]+b[i][j]<<" ";
		cout<<"\n";
	}

}

void matrix::sub()
{	for(int i=0;i<m;i++)
	{	for(int j=0;j<m;j++)
			cout<<a[i][j]-b[i][j]<<" ";
		cout<<"\n";
	}
}

void matrix::mul()
{	int c[10][10];
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			c[i][j]=0;
	
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			for(int k=0;k<m;k++)
				c[i][j]+=a[i][k]*b[k][j];
	for(int i=0;i<m;i++)
	{	for(int j=0;j<m;j++)
			cout<<c[i][j]<<" ";
		cout<<"\n";	
	}
}

void matrix::saddle()
{	cout<<"\nSaddle points of matrix A : ";	
	for(int i=0;i<m;i++)
	{	for(int j=0;j<m;j++)
		{	int max=a[i][j];
			for(int k=0;k<m;k++)
			{	if(max<a[j][k])
					max=a[i][k];
			}
			int min=a[i][j];
			for(int k=0;k<m;k++)
			{	if(min>a[k][j])
				min=a[k][j];
			}
			if(min==max)
				cout<<min<<" ";
		}
	}
}

int main()
{	matrix d;
	int ch;
	char c;
	
	
	d.get();
	do
	{
	cout<<"\nMENU\n1.Check for upper triangular matrix\n2.Find transpose of matrix\n3.Sum of the diagonal of matrix\n4.Addition of two matrices\n5.Subtraction of two matrices\n6.Multiplication of two matrices\n7.Saddle Points";	
	cout<<"\nEnter your choice :";
	cin>>ch;
	
	switch(ch)
	{	
		case 1: d.upper_triangle();
			break;
		case 2: cout<<"\nThe transpose of matrix A :\n";
			d.transpose();
			break;
		case 3: cout<<"\nSum of diagonal of matrix A :";
			d.sum_diag();
			break;
		case 4: cout<<"\nAddition of matrix A and B :\n";
			d.add();
			break;
		case 5: cout<<"\nSubtraction of matrix A and B :\n";
			d.sub();
			break;
		case 6: cout<<"\nMultiplication of matrix A and B :\n";
			d.mul();
			break;
		case 7: d.saddle();
			break;
	}
	cout<<"\n\nWant to continue (y/n) : ";
	cin>>c;
	}while(c=='y');
	return 0;
}
