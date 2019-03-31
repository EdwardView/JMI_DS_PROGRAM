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
class linklist
{
	node *first;
	public:
		linklist(){
			first = NULL;
		}
		bool isEmpty();
		int getsize();
		void insert(int,int);
		int del(int);
		int getdata(int);
		int indexof(int);
		void display();
		void reverse();
		void shiftright_left(int);
		void shiftleft_right(int);
		void merge(linklist &);
};

int linklist :: indexof(int n){
	if(isEmpty() == 1)
		cout << "List is Empty.\n";
	int index = -1,i=0;
	node *current = first;
	while(current != NULL){
		if(current->data == n){
			index = i;;
			break;
		}
		i++;
		current = current->next;
	}
	return index;
}
bool linklist :: isEmpty()
{
	if(first == NULL)
		return true;
	else
		return false;
}
int linklist :: getsize()
{
	int size = 0;
	node *current = first;
	while(current != NULL){
		current = current->next;
		size++;
	}
	return size;
}
void linklist :: insert(int x,int index){
	if(index < 0 || index > getsize()){
		throw arryException("invalid index in Insertion.\n");
	}
	node *current = new node;
	current->data = x;
	if(index == 0){
		current->next = first;
		first = current;
	}
	else{
		node *prev = first;
		for(int i=0; i<index-1; i++){
			prev = prev->next;
		}
		current->next = prev->next;
		prev->next = current;
	}
}
void linklist :: display()
{ 
	node *current = first;
	cout << "[ ";
	while(current != NULL){
		cout << current->data;
		current = current->next;
	}
	cout << " ]\n";
}
int linklist :: del(int index)
{
	node *del,*prev;
	int n;
	if(index < 0 || index >= getsize()){
		cout << "invalid index\n";
	}
	if(index == 0){
		del = first;
		first = del->next;
		n = del->data;
		delete del;
	}
	else{
		prev = first;
		for(int i=0; i<index-1; i++){
			prev = prev->next;
		}
		del = prev->next;
		prev->next = del->next;
		n = del->data;
		delete del;
	}
	return n;
}
int linklist :: getdata(int index)
{
	if(index < 0 || index >= getsize())
		cout << "Invalid Index.\n";	
	node *current=first;
	for(int i=0; i<index; i++)
		current = current->next;
	return current->data;
}
void linklist :: reverse(){
	if(getsize() <= 0)
		return;
	node *pre = first;
	node *current = pre->next;
	node *link = current->next;
	first->next = NULL;
	while(current != NULL){
		current->next= pre;
		pre = current;
		current = link;
		if(link != NULL)
			link = link->next;
	}
//	current->next = pre;
	first = pre;
}
void linklist :: shiftright_left(int bit)
{
	for(int i=0; i<bit; i++){
		node *last = first;
		node *prev = NULL;
		while(last->next != NULL){
			prev = last;
			last = last->next;
		}
		last->next = first;
		first = last;
		prev->next = NULL;
	}
}
void linklist :: shiftleft_right(int bit)
{
	for(int i=0; i<bit; i++){
		node *last = first;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = first;
		first = first->next;
		last->next->next = NULL;
	}
}
void linklist :: merge (linklist &l2){
	node *current = first;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = l2.first;
} 

int main(){
	cout <<"2.To create and Insert data at particular index in linklist.\n3.Is Empty linkl.\n4.Merge two linklist.\n5.Left to Right Shift 		linklist.\n6.Right to Left linklist.\n7.Sort Linklist.\n8.Delete any node in a linklist by its index.\n9.Get the index of Data in  		Linklist.\n10.Display the Linklist.\n";
	linklist l1;
	for(int i=0; i<5; i++)
		l1.insert(i+1,i);
	l1.display();	
	linklist l2;
	for(int i=0; i<5; i++)
		l2.insert(i+1,i);
	l2.display();
	l1.merge(l2);
	cout << "After the merging two linklist:\n";
	l1.display();
	cout << "\n To delete particular element in a list.\n";
	for(int i=0; i<3; i++)
	cout << l1.del(0);
	cout << "After deleting :\n";
	l1.display();
	cout << "Get the Value at index 0. \t"<< l1.getdata(0) << endl;
	cout << "Get the Index of 1 in the list. \t" << l1.indexof(1) << endl;
	l1.display();
	cout <<"After Shifting Right-left list at " << l1.getsize()-1 << "time list will be." <<  endl;
	l1.shiftright_left(l1.getsize()-1);
	l1.display();
	cout <<"After Shifting left-Right list at " << l1.getsize()-1 << "time list will be." <<  endl;
	l1.shiftleft_right(l1.getsize()-1);
	l1.display();	
	cout << "Reversing the list : \n";
	l1.reverse();
	l1.display();
	return 0;
}

