#include<iostream>
using namespace std;
class Node{
	public:
	//char data;
	Node *data;
	Node * link;
	Node(){ link = NULL; data = NULL; }
};
class QueueLinklist{
	Node * front,*rear;
	public:
		QueueLinklist(){ front = rear = NULL;}
		bool isEmpty();
		void insert(Node *);
		char delete_in_Q();
		void display();
	//	int getfront(Node *);
	//	int getrear(Node *);		
};
bool QueueLinklist :: isEmpty()
{
	if(front == NULL && rear == NULL)
		return true;
	else
		return false;
}
void QueueLinklist :: display()
{
	Node *current = front;
	while(current->link != NULL){
		cout << current->data;
		current = current->link;
	}
	cout << current->data;
}
void QueueLinklist :: insert(Node * d)
{
	Node *current = new Node; 
	current->data = ch;
	if(front == NULL){
		front = rear = current;
	}
	else
	{
		rear->link = current;
		rear = current;
	}
}
char QueueLinklist :: delete_in_Q(){
	if(rear == NULL){
		cout << "Empty Queue\n";
	}
	char ch;
	if(front == rear){
		Node * del = front;
		ch = front->data;
		front = rear = NULL;
		delete del;
	}
	else{
		Node * prev,*curr;
		prev = front;
		while(prev -> link != NULL){
			curr = prev;
			prev = prev->link;
			
		}	
		Node *del = prev;
		curr->link = NULL;
		ch = del->data;
		rear = curr;
		delete del;
	}
	return ch;
}
int main(){
	QueueLinklist Q;
	Q.insert('A');
	Q.insert('B');
	Q.insert('C');
	Q.insert('D');
	Q.insert('E');
	Q.display();
	cout << "\n" << Q.delete_in_Q() << endl;
	Q.display();
	return 0;s
}
