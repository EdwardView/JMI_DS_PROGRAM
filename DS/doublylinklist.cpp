//DOUBLY LINKED LIST.
#include<iostream>
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
	node *next,*prev;
		node(){
			next = NULL;
			prev = NULL;
		}
};
class Dlinklist
{
	node *first;
	public:
		linklist(){
			first = NULL;
		}
		bool isEmpty();
		node * create(int n);
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
bool Dlinklist :: isEmpty(){
    if(getsize() == 0)
        return true;
    else
        return false;
}
    }
node * Dlinklist :: create(int n){
    node * current = first;
    for(int i=0; i<n; i++){
    if(i == 1){
        first = current = new node();
    }
    else{
        current->next = new node();
        node * Next = current->next;
        Next->prev  = current;
        current = next;
     }
     cout << "Enter the data  : \n";
     cin >> current->data;
    }
    first->prev = current->next = NULL:
}
int Dlinklist :: getsize(){
    node *current = first;
    int size = 0;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;
}
int Dlinklist :: insert(int x,int index){
    if(index < 0 or index > getsize())
        throw arryException("Invalid Index value.\n");
    node * Nnode = new  node();
    Nnode->data = x;
    if(index == 0){
        Nnode->next = first;
        if(first->prev != NULL){
            first = Nnode;
        }
    }
    else{
        node * prevs = first;
        for(int i=0; i<index; i++){
            prevs = prevs->next;
        }
    }
}
void Dlinklist :: display(){
    node * curret = first;
    if(isEmpty() == true){
        cout << "Dlinklist is Empty.\n";
        return ;
    }
    while(current != NULL){
          cout << "DATA = " << current->data;
          current = current->next;
        }
}
