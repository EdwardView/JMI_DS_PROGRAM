#include<iostream>
using namespace std;
int map(int i,int j){return i*(i+1)/2+j;}
class LTmatrix
{
	float *a;
	int n;
	public : 
		LTmatrix(int n)
		{
			this->n = n;
			a = new float[n*(n+1)/2];
		}
		void read();
		void print();
		float det();
		LTmatrix MUL(LTmatrix B);
	        LTmatrix ADD(LTmatrix B);
		LTmatrix inverse();
};
void LTmatrix :: read()
{
	cout << "Total matrix element :  " << n*(n+1)/2 << endl;
	cout << "Entre the Elemnt of matrix : \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{	
			cin >> a[map(i,j)];
		}
	}
}
void LTmatrix :: print()
{
	cout << "Lower Triangular Matrix : \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>=j)
			{
				cout << a[map(i,j)] << "\t";
			}
			else
				cout << "O\t";
		}
		cout << "\n";
	}
}
float LTmatrix :: det()
{
	float d = 1;
	for(int i=0; i<n; i++)
	{
		d = d*a[map(i,i)];
	}
	return d;
}
LTmatrix LTmatrix :: ADD(LTmatrix B)
{
	LTmatrix temp(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i>=j)
				temp.a[map(i,j)] = a[map(i,j)] + B.a[map(i,j)];
		}
	}
	return temp;
}
LTmatrix LTmatrix :: MUL(LTmatrix B)
{
	LTmatrix temp(n);
	cout << "MULTIPLICATION : \n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			for(int k=j; k<=i; k++)
				temp.a[map(i,j)] += a[map(i,k)] * B.a[map(k,j)];
		}
	}
	return temp;
}

int main()
{
	cout << "Entre the size of matrix : \n";
	int n;
	cin >> n;
	LTmatrix l1(n);
	l1.read();
	l1.print();
	cout << "Determinent = " << l1.det() << endl;
	cout << "Second Matrix : \n";
	LTmatrix l2(n);
	l2.read();
	l2.print();
	l2.det();
	cout << "Thrid matrix : \n ";
	LTmatrix l3(n);
	cout << "ADDITION : \n";
	l3 = l1.ADD(l2);
	l3.print();
	cout << "MULTIPLICATION :\n";
	l3 = l1.MUL(l2);
	l3.print();
	return 0;
}


				
			
				

