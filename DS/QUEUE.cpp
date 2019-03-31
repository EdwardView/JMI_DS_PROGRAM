 // QUEUE IMPLEMNTETION UISNG ARRAY

#include<iostream>
using namespace std;

class queue{
		//int *a;
		int a[10];
		int rear,front,length;
		public:
			queue();
			bool isEmpty();
			void insert(int);
			int delete_in_Q();
			void display();
			int getfront();
			int getrear();	
};
queue :: queue(/*int i*/){
  //	a = new int[i];   
	rear = front = -1;
	length = 10;
}
bool queue :: isEmpty(){
	if(rear == -1)
		return true;
	else
		return false;
}
void queue :: insert(int x){
	if(rear == length-1){
		cout << "Queue Overflow.\n";
		return ;
	}
	if(rear == -1)
		front = rear = 0;
	else
		rear++;
	a[rear] = x;	
}
int queue :: delete_in_Q(){
	if(front == -1){
		cout << "Queue Empty.\n";
	}
	int x = a[front];
	if(rear == front)
		rear = front = -1;
	else
		front++;		
	return x;
}
void queue :: display(){
	for(int i=front; i<=rear; i++){
		cout << a[i] << "\t" ;
	}
}
int queue :: getfront(){
	if(isEmpty() == false)
		return a[front];
	else 
		return -1;
}
int queue :: getrear(){
	if(isEmpty() == false){
		return a[rear];
	}
	else
		return -1;
}
//int main(){
//	
//	queue q1(5);
//	//char ch = 'A';
//	
//	for(int i=0; i<5; i++)
//		q1.insert(i+1);
//	
//	q1.display();
//	
//	cout << "Delete in Queue : " << q1.delete_in_Q() << endl;
//	q1.display();
//	return 0;
//}
