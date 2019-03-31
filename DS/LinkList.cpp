#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class person
{
	string name;
	int height;
	float weight;
	public :
		float BMI();
		string msg();
		friend istream &operator>> (istream &abc,person &x);
		friend ostream &operator<< (ostream &abc,person x);
};
float person :: BMI()
{
	return (weight/(height*height)*10000);
}
istream &operator >>(istream &abc,person &x)
{
	cout << "Enter the name : \n";
	//cin.clear();
	//fflush(stdin);
//	getchar();
	getline(abc,x.name);
	cout << "Entre the height(in cm) : \n";
	abc  >> x.height;
	cout << "Entre the weight(in kg) :\n";
	abc >> x.weight;
	return abc;
}
ostream &operator <<(ostream &abc,person x)
{
	float bmi = x.BMI();
	abc << "[NAME : " << x.name << " WEIGHT : " << x.weight << " HEIGHT : " << x.height << " BMI : " << bmi << "]\n";
	return abc;
}
class Node
{
	public :
	person data;
	Node * link;
	public :
		Node()
		{
			this->link = NULL;
		}
};
class linklist
{
	Node *first;
	public :
		linklist(){
			first = NULL;
		}
		bool isEmpty();
		int getsize();
		void insert(person,int);
		person del(int);
		person getdata(int);
		void display();
};
bool linklist :: isEmpty()
{
	if(getsize() == 0)
		return true;
	else
		return false;
}
int linklist :: getsize()
{
	int size = 0;
	Node *current = first;
	while(current != NULL){
		size++;
		current = current->link;
	}
	return size;
} 
void linklist :: insert(person x,int index)
{
	if(index < 0 || index > getsize())
	{
		cout << "Invalid index\n";
		return;
	}
	Node *current = new Node;
	current->data = x;
	if(index == 0){
		current->link = first;
		first = current;
	}
	else
	{
		Node *prev = first;
		for(int i=0; i<index-1; i++){
			prev = prev->link;
		}
		current->link = prev->link;
		prev->link = current;
	}
}
person linklist :: del(int index)
{
	Node *del,*prev;
	person p;
	if(index < 0 || index >= getsize()){
		cout << "invalid index\n";
	}
	if(index == 0){
		del = first;
		first = del->link;
		p = del->data;
		delete del;
	}
	else{
		prev = first;
		for(int i=0; i<index-1; i++){
			prev = prev->link;
		}
		del = prev->link;
		prev->link = del->link;
		p = del->data;
		delete del;
	}
	return p;
}
void linklist :: display()
{
	Node *current = first;
	while(current->link != NULL){
		cout << current->data;
		current = current->link;
	}
	cout << current->data;
}
person linklist :: getdata(int index)
{
	if(index <  0 || index >= getsize()){
		cout << "index is invalid\n";
		exit(1);
	}
	Node *current = first;
	for(int i=0; i<index; i++)
		current = current->link;
       return current->data;
}

int main()
{
	linklist l1;
	cout << "WELCOME BMI calaulation ststem of student.\n";
	while(1){
		cout << "1.Insert Students Record.\n2.Delete Record(by index).\n3.Getdata of Student(by index).\n4.Display().\n5.exit.\n";
		person p;
		int ch,n;
		cout << "Enter your choice.\n";
		cin >> ch;
		switch(ch){
			case 1:{
				cout << "How many record you want insert.";
				cin >>n;
				for(int i=0; i<n; i++){
					cout << "Enter data of student : " << i+1 << endl;
					cin >> p;
					l1.insert(p,i);
				}}
				break;
			case 2:{
				cout << "Which of index record you want delete\n";
				cin >> n;
				p = l1.del(n);
				cout << p;
			       }
			       break;
			case 3:
			       {
				       cout << "Which of index record you want dispaly.\n";
				       cin >> n;
				       p = l1.getdata(n);
				       cout << p;
			       }
			       break;
			case 4:
			   	l1.display();
				break;
			case 5:
				exit(1);
				break;
			default:
				cout << "!!!!Enter the valid option.\n";
		}
		continue;
	}
	return 0;
}
