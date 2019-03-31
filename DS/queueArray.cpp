//			QUEUE USING ARRAY.
//			MOHD SAHIL WARSI (20/2/19)

#include<iostream>
#include<string.h>
using namespace std;
class arryException{
	char *s;
	public :
	arryException(char x[])
	{
		s = new char[strlen(x)+1];
		strcpy(s,x);
	}
	friend ostream &operator<< (ostream &abc,arryException a)
	{
		abc << a.s;
	}
};
class QUEUE
{
	int *ary,front,rear,length;
	public :
			QUEUE(int);
			bool isEmpty();
			int getsize();
			void insert(int);
			int del();
			void display();
};
QUEUE :: QUEUE(int n){
	ary = new int[n];
	front = rear = -1;
	length = n;
}
bool QUEUE :: isEmpty(){
	if(rear  == -1)
		return true;
	else
		return false;
}
int QUEUE :: getsize(){
	return rear-front+1;
}
void QUEUE :: insert(int x){
	if(rear == length-1)
		throw arryException("QUEUE is full.\n");

	if(rear == -1)
			front = rear = 0;
	else
			rear++;
	ary[rear] = x;
}
int QUEUE :: del(){
	if(front == -1)
		throw arryException("QUEUE is Empty.\n");

	int x = ary[front];
	if(rear == front)
		rear = front = -1;
	elseo
		front++;
	return x;
	
}

void QUEUE :: display(){
	cout << "QUEUE ELEMENTS : \n[ ";
	for(int i=front; i<=rear; i++){
			cout << ary[i] << ", "; 	
	}
	cout << "\b\b]\n";
}
int main(){
	cout << "Enter the total  Number of  element insert in QUEUE : \n ";
	int n;
	cin >> n;
	QUEUE q1(n);
	for(int i=0; i<n; i++)
		q1.insert(i);
	q1.display();
	cout << "\nDeleted Element : " << q1.del() << endl;
	q1.display();
	return 0;
}
