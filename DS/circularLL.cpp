#include<iostream>
#include<cstring>
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
class node
{
	public :
	int data;
	node *next;
		node(){
			next = NULL;
		}
};
class circularLL
{
	node *first;
	public:
		circularLL(){
			first = NULL;
		}
		bool isEmpty();
		void createNode(int);
		int getsize();
		void insert(int,int);
		int del(int);
		int getdata(int);
		int indexof(int);
		void display();
		void shiftright_left(int bit);
		void shiftleft_right(int bit);
};
bool circularLL :: isEmpty(){
	if(first == NULL)
		return 1;
	else
		return 0;
}
int circularLL :: getsize(){
	if(isEmpty())
		return 0;
	int size=1;
	node *current = first;
	while(current->next != first){
		current = current->next;
		size++;
	}
	return size;
}
void circularLL :: createNode(int n){
	node * current = first;
	for(int i=1; i<=n; i++){
		if(i==1){
			current = new node();
			first = current;
		}
		else{
			current->next = new node();
			current = current->next;
			}
		cout << "Enter the data : \n";
		cin >> current->data;
		current->next = first;
	}
}
void circularLL :: insert(int x,int index){
	if(index<0 || index>=getsize())	
		throw arryException("Invalid Index.\n");
	node *newnode = new node();
	newnode->data = x;
	node * last = first;
	if(index == 0){
		last = first;
		while(last->next != first){
			last = last->next;
		}
		newnode->next = first;
		last->next = newnode;
		first = newnode;
	}
	else{
		node *prev = first;
		for(int i=0; i<index-1; i++){
			prev = prev->next;
		}
		newnode->next = prev->next;
		prev->next = newnode;
	}
}	
int circularLL :: del(int index){
	if(index<0 || index>=getsize())
		throw arryException("Invalid Index");
	int x;
	if(index == 0){
		node *last = first;
		while(last->next != first){
			last = last->next;
		}
		node *del = first;
		x = del->data;
		if(last == first)
			first = NULL;
		else{
			last->next = del->next;
			first = del->next;
			delete del;
		}
	}
	else{
		node *prev = first;
		for(int i=0; i<index-1; i++){
			prev = prev->next;
		}
		node *del = prev->next;
		x = del->data;
		prev->next = del->next;
		delete del;
	}
	return x;
}
int circularLL :: indexof(int x){
	if(first == NULL)
		return -1;
	int index = -1,i=0;
	node *current = first;
	while(current->next != first && current->data != x){
		current = current->next;
		i++;
	}
	if(current->data = x)
		index = i;
	return index;
}
void circularLL :: display(){
	node *current = first;
	if(first == NULL){
		cout << "List is Empty.\n";
		return ;
	}
	cout << "[ ";
	while(current->next != first){
			cout << current->data << ",";
			current = current->next;
	}
	cout << current->data << "]" << endl;
}
void circularLL :: shiftright_left(int bit)
{
	if(getsize() == 1)
		return;
	if(bit > 0){
	for(int i=0; i<bit; i++){
		node *last = first;
		node *prev = NULL;
		while(last->next !=first){
			prev = last;
			last = last->next;
		}
		last->next = first;
		first = last;
		prev->next = first;
	}
	}
	else
		cout << "Shift value is -ve.\n";
}
void circularLL :: shiftleft_right(int bit)
{
	if(getsize() == 1)
		return;
	if(bit > 0){
	for(int i=0; i<bit; i++){
		node *last = first;
		while(last->next != first){
			last = last->next;
		}
		last->next = first;
		first = first->next;
		last->next->next = first;
	}
	}
	else
		cout << "Shift value is -ve.\n";
}
int main(){
	circularLL cl1;
	cl1.createNode(5);
	cl1.display();
/*	for(int i=0; i<5; i++)	
		cl1.insert(1+i+2,i);
	cl1.display();
	cout << "Size of CLL is :  " << cl1.getsize() << endl;
	for(int i=0; i<cl1.getsize()/2; i++){	
		cout << "Delete element : " << i+1 << "\t" << cl1.del(i) << endl;	
		cl1.display();	
	}
	cl1.display();	
	int i = cl1.indexof(3);
	if(i < 0)
		cout << "Element is not presecne in the list.\n";
	else
		cout << "Index = : " << i << endl;*/
	cl1.display();
	cl1.shiftright_left(2);
	cl1.display();
	cl1.shiftleft_right(2);
	cl1.display();
	return 0;



}
