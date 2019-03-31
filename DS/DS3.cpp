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
class array
{
	int *ary,length,size;
	public :
		array(int n);
		int getsize();
		void insert(int,int);
		int del(int);
		void display();
		int getindex(int);
		int index(int);
};
array :: array(int n)
{
	length = n;
	ary = new int[n];
	size=0;
}
int array :: getsize()
{
	return size;
}
void array::insert(int x, int index){
	if(index < 0 || index > size)
		throw ArrayException("Invalid index in insertion operation");
	for(int i = size - 1; i >= index; i--)
	   ary[i+1] = ary[i];
	ary[index] = x;
	size++;
}

void array :: display()
{
	cout << "[ ";
	for(int i = 0; i < size; i++)
		cout << ary[i] << ", ";
	cout << "]" << endl;
}
int array :: del(int index)
{	
	if(index < 0 || index >= size)
		throw ArrayException("Invalid deletion index.");
	int x = ary[index];	
	for(int i=index; i<size-1; i++)
		ary[i] = ary[i+1];
	size--;
	return x;
}
void getpatter(array &a,int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
			a.insert(i+1,a.getsize());
	}
}
void minremovepattern(array &a,int n)
{
	for(int i=1; i<=n-1; i++)
	{
		for(int j=1; j<=n-i; j++)
			a.del(a.getsize()-i);
	}
}
void maxremovepattern(array &a,int n)
{
	for(int i=1; i<=n-1; i++)
	{
		for(int j=1; j<=i; j++)
			a.del(i);
	}
}
int array :: getindex(int index)
{
	if(index < 0 || index >= size)
		throw ArrayException("Index out of range.\n");
	return *(ary+index);
}
int array :: index(int x)
{
	for(int i=0; i<size; i++)
	{
		if(ary[i] == x)
			return i;
	}
	return -1;
}
int main()
{
	cout << "Entre the length of array :\n";
	int n;
	cin >> n;
	array A(n);

	getpatter(A,n);
	A.display();
	maxremovepattern(A,n);
        A.display();
	int abc = A.getindex(n-1);
	cout << "Index of " << n << " is : " << abc << endl;
	int i = A.index(n);
	if(i == -1)
		cout << "Element in not present.\n";
	else
		cout << "Index of " << n << "is : " << i+1 << endl;
	return 0;
}
