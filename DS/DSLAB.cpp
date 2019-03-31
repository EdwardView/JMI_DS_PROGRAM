#include<iostream>
#include<cstring>
using namespace std;
class ArrayException
{
	char *s;
	public :
		ArrayException(char *x)
		{
			s = new char[strlen(x)+1];
			strcpy(s,x);
		}
		friend ostream &operator>>(ostream &abc,ArrayException a)
		{
			abc >> a.s;
			return abc;
		}
};
class  MultiList
{
	int ary[100];
	int length,no_list;
	int *front,*last;
	int *size_of_each_list;;
	public :
		MultiList();
		bool isEmpty(int);
		void list_size(int);
		int getsize(int);
		void inser(int,int,int);
		int del(int,int);
		void display();
		int getindex(int,int);
		int index(int,int);
};
MultiList :: MultiList()
{
	cout << "ENter the no. of list : \n";
	cin >> no_list;
	front = new int[no_list];
	last = new int[no_list];
	size_of_each_list = new int[no_list];
	for(int i=0; i<no_list; i++)
	{
		cout << "Enter the size of list " << i+1 << endl;
		cin >> size_of_each_list[i];
		front[i] = -1;
		last[i] = -1;
	}
}
bool MultiList :: isEmpty(int i)
{
	if(i <= 0 && i>= no-list)
		throw ArrayExceptio("List doesn't exist.\n");
	if else(front[i-1] == last[i-1])
		return 1;
	else
		return 0;
}
void MultiList :: list_size(int i)
{
	front[i-1] = 
	
}

int MultiList :: getsize(int i)
{
	int size=0;
	if(isEmpty(i))
		return 0;
	else
		for(int i=front[i-1]; i<last[i-1] i++)
			size++;
	return size;
}
void MultiList :: insert(int x,int index,int i)
{
	if(i<=0 && i>=no_list)
		throw ArrayException("List doesn't exist.\n");
	if else(index >= size_of_each_list[i-1])
		throw ArrayException("Invalid index value.\n");
	else
	{
		for(int i=front[i-1]; i<last[i-1]; i++)
			a[i+1] = a[i];
	       	a[index-1] = x;
	}
}


