#include<iostream>
#include<cstring>
using namespace std;
class ArrayException{
	char *s;
	public:
		ArrayException(char *x){
			s = new char[strlen(x) + 1];
			strcpy(s, x);
		}
		friend ostream &operator<<(ostream &abc, ArrayException a){
			abc << a.s;
			return abc;
		}
};
class Diagonal_Matrix
{
	float *M;
	int n;
	public :
		Diagonal_Matrix();
		void read();
		void print();
		Diagonal_Matrix add(Diagonal_Matrix &);
		Diagonal_Matrix mul(Diagonal_Matrix &);
		float det();
		Diagonal_Matrix inverse();
		Diagonal_Matrix tranpose();
	        Diagonal_Matrix	scalarMul(int);
};
Diagonal_Matrix :: Diagonal_Matrix()
{
	cout << "Enter the size of Diagonl  matrix :\n";
	cin >>n;
	M = new float[n];
}

void Diagonal_Matrix :: read()
{
	cout << "Enter the Diagonal Matrix Element ( " << n << "*" << n << ")" << endl;
	for(int i=0; i<n; i++)
		cin >> M[i];
}
void Diagonal_Matrix :: print()
{
	cout << "Diagonal Matrix Element : \n ";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i == j)
				cout << M[j] << "\t";
			else
				cout << "0" << "\t";
		}
		cout << endl;
	}
}
Diagonal_Matrix Diagonal_Matrix :: add(Diagonal_Matrix &B)
{
	Diagonal_Matrix sum;
	if(n == B.n)
	{
		for(int i=0; i<n; i++)
			sum.M[i] = M[i] + B.M[i];
	}
	else
		throw ArrayException("Invalid Addition due to size miss Match.\n");
	return sum;
}	
Diagonal_Matrix Diagonal_Matrix :: mul(Diagonal_Matrix &B)
{
	Diagonal_Matrix mult;
	if(n == B.n)
	{
		for(int i=0; i<n; i++)
			mult.M[i] = M[i] * B.M[i];
	}
	else
		throw ArrayException("Multiplication is not possible.\n ");
	return mult;
}
float  Diagonal_Matrix :: det()
{
	float det_min = 1;
	for(int i=0; i<n; i++)
		det_min *= M[i];
	return det_min;
}
Diagonal_Matrix Diagonal_Matrix :: inverse()
{
	Diagonal_Matrix t;
	for(int i=0; i<n; i++)
		t.M[i] = 1.0/M[i];
	return t;
}
Diagonal_Matrix Diagonal_Matrix :: tranpose()
{
	 Diagonal_Matrix t;
	for(int i=0; i<n; i++)
		t.M[i] = M[i];
	return t;
}
Diagonal_Matrix Diagonal_Matrix :: scalarMul(int s)
{
	 Diagonal_Matrix t;
	for(int i=0; i<n; i++)
		t.M[i] = s * M[i];
	return t;
}

int main()
{
	Diagonal_Matrix D1;
	D1.read();
	D1.print();
	Diagonal_Matrix D2;
	D2.read();
	D2.print();
	cout << "SUM of matrix D1 and D2  : \n";
	Diagonal_Matrix sum = D1.add(D2);
	sum.print();
	cout << "Multiplaction of matrix D1 and D2  : \n";
	Diagonal_Matrix mult = D1.mul(D2);
	mult.print();
	cout << "DETERMINET OF MATRIX : " << D1.det() << endl;
	if(D1.det() == 0)
		cout << "Inverse of Matrix doesnot exist.\n";
	else
	{
		cout << "INVERSE of MATRIX : " << endl;
	 	Diagonal_Matrix inv = D1.inverse();
		inv.print();
	}
	cout << "Transpose of Matrix : \n";
	Diagonal_Matrix trans = D1.tranpose();
	trans.print();
	cout << "Scalar Multiplaction of Matrix : \n";
	Diagonal_Matrix sc = D1.scalarMul(5);
	sc.print();
	return 0;
}
		

