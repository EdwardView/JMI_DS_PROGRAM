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

//gcd using stack
int gcd(int m,int n)
{
	stack<int> s1(1),s2(1);
	s1.push(m);
	s2.push(n);
	while(s1.isEmpty()==false)
	{
		m=s1.pop();
		n=s2.pop();
		if(m%n!=0)
		{
			s1.push(n);
			s2.push(m%n);
		}
	}
	return n;
}
//tower of hanoi using stack
void move(int n)
{
	stack<int> s1(pow(2,n));
	stack<char> s2(pow(2,n)),s3(pow(2,n)),s4(pow(2,n));
	s1.push(n);
	s2.push('A');
	s3.push('B');
	s4.push('C');
	while(s1.isEmpty()==false)
	{
		n=s1.pop();
		char s=s2.pop();
		char i=s3.pop();
		char d=s4.pop();
		if(n>1)
		{
			s1.push(n-1); s2.push(i); s3.push(s); s4.push(d);
			
			s1.push(1); s2.push(s); s3.push(i); s4.push(d);
			
			s1.push(n-1); s2.push(s); s3.push(d); s4.push(i);
		}
		else{
			cout<<"\nmove "<<s<<"->"<<d;
		}
		
	}
}
//factorial using stack 
int fact(int n)
{
	stack<int> s(n-1);
	while(n>1)
	{
		s.push(n);  //s.push(n--)
		n--;
	}
	int f=1;
	while(s.isEmpty()==false)
	{
		f=f*s.pop();
	}
	return f;
}
//sum of digits of a positive number using stack
int sum_digits_of(int n)
{
	int d=floor(log10(n))+1;
	stack<int> s(d);
	int sum=0;
	while(n)
	{
		s.push(n%10);
		n=n/10;
	}
	while(s.isEmpty()==false)
	{
		sum=sum+s.pop();
	}
	return sum;
}
//decimal to binary using stack
int dec_bin(int n)
{
	int d=floor(log2(n))+1;
	stack<int> s(d);
	int bin,i=d;
	while(n)
	{
		s.push(n%2);
		n=n/2;
	}
	while(s.isEmpty()==false)
	{
//		cout<<s.pop();
		i=i-1;
		bin=bin+s.pop()*pow(10,i);
	}
	return bin;
}
//dec to octal using stack

int dec_oct(int n)
{
	int d=floor(((log2(n))/3))+1;
	stack<int> s(d);
	int oct,i=d;
	while(n)
	{
		s.push(n%8);
		n=n/8;
	}
	while(s.isEmpty()==false)
	{
//		cout<<s.pop();
		i=i-1;
		oct=oct+s.pop()*pow(10,i);
	}
	return oct;
}
//reverse of a number using stack;
int reverse(int n)
{
	int d=floor(log10(n))+1;
	stack<int> s(d);
	while(n)
	{
		s.push(n%10);
		n=n/10;
	}
	int rev=0,i=0;
	while(s.isEmpty()==false)
	{
		rev=rev+s.pop()*pow(10,i);
//		cout<<s.pop();
		i++;
	}
	return rev;
}
int fibonacci(int n)
{
	stack<int> s(2);
	int fib;
	if(n==1)
	{
		return 0;
	}
	s.push(0);
	s.push(1);
	while(n>2)
	{
		int x=s.pop();
		int y=s.pop();
		fib=x+y;
		s.push(x);
		s.push(fib);
		n=n-1;
	}
	return s.pop();
}
int main()
{
	int a=12,b=18;
	
	cout<<"gcd of 12 and 18 is:"<<gcd(a,b)<<endl;
	cout<<"\ntower of hanoi for 3 disks:\n";
	move(3);
	cout<<"\nfact of 5 is:"<<fact(5);
	cout<<"\nsum of digits of 876 is:"<<sum_digits_of(876);
	cout<<"\ndec to bin of 16 is:"<<dec_bin(16);
	cout<<"\ndec to oct of 70 is:"<<dec_oct(70);
	cout<<"\nreverse of 1234 is: "<<reverse(1234);
	cout<<"\nfibonacci 6th is:"<<fibonacci(6);
	getch();
	return 0;
}

