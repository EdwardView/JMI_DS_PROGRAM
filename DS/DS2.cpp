#include<iostream>
#include<cstring>
using namespace std;
/*class arryException{
	char *str;
	public :
	arryException(char x[])
	{
		str = new char[strlen(x)+1];
		strcpy(str,x);
	}
	friend ostream &operator<< (ostream &abc,arryException a)
	{
		abc << a.str;
	}
};*/
class array
{
	int *ary,size;
	public :
		array(int);
		void display();
		void getpattern(array,int);
		void removeduplicate(array,int);
};
array :: array(int n)
{
	ary = new int[n];
}
void array :: getpattern(array a,int n)
{
	for(int i=0,k=0; i<n && k<size; k++)
	{
		for(int j=0; j<=k; j++,i++)
		{
			ary[i] = k+1;
		}
	}
}
void array :: display()
{
	for(int i=0; i<size; i++)
		cout << ary[i];
}
int main()
{
	int n;
	cout << "Entre the number to which store pattern : \n";
	cin >> n;
	array a(n*(n+1)/2);
	a.getpattern(a,n);
	a.display();
}
