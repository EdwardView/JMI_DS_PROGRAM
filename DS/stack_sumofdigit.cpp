#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
template <class T>
class stack{
	T *a;
	int length,tos;
	public:
		stack(int n)
		{
			length=n;
			a=new T[n];
			tos=-1;
		}
		bool isEmpty();
		int getSize();
		void push(T x);
		T pop();
		void display();
		int sum_of_digit(int n);
};
template <class T>
bool stack<T>::isEmpty()
{
	if(tos==-1)
		return true;
	else
		return false;
}
template <class T>
int stack<T>::getSize()
{
	return tos+1;
}
template <class T>
void stack<T>::push(T x)
{
	a[++tos]=x;
}
template <class T>
T stack<T>::pop()
{
	return a[tos--];
}
template <class T>
void  stack<T>::display()
{
	cout<<"[";
	for(int i=tos; i>=0; i--)
	{
		cout<<a[i]<<", ";
	}
	cout<<"\b\b]";
}
template <class T>
int stack<T>::sum_of_digit(T n){
	int temp = n;
	stack s1(log10(n)+1);
	while(temp!=0){
		s1.push(temp%10);
		temp/=10;
	}
	int digit=0;
	while(s1.isEmpty() == false){
		digit +=s1.pop();
	}
	return digit;
}
  
