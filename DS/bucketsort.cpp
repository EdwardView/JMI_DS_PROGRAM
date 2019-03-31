#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void BucketSort(int *a,int n);
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
};
int getmax(int *a,int n){
	int temp = a[0],i=1;
	while(i<n){
		if(temp < a[i]){
			temp = a[i];
		}
		i++;
	}
	return temp;
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

void BucketSort(int *a,int n){
	int max = getmax(a,n);
	linklist l[max+1];
	for(int i=0; i<n; i++){
		l[a[i]].insert(a[i],0);
	}
	int k=0;
	for(int i=0; i<max+1; i++){
		while(l[i].isEmpty() == false){
			a[k] = l[i].del(l[i].getsize()-1);
			k++;
		}
	}
}
void radixsort(int *a,int n){
	int max = getmax(a,n);
	int d = floor(log10(max)) +1;
	cout << "Digit : " << d << endl;
	linklist l[10];
	for(int i=1; i<=d; i++){
		for(int j=0; j<n; j++){
			int f = floor(a[j]/pow(10,i-1));
			l[f%10].insert(a[j],0);
			//cout << "\nSORT\n";
		}
		int k=0;
		for(int j=0; j<10; j++){
			while(l[j].isEmpty() == false){
				a[k] = l[j].del(l[j].getsize()-1);
				k++;
			}
		}	
	}
}
		
int main()
{
	int *a,n;
	cout << "ENTER  THE SIZE OF ARRAY : \n";
	cin >> n;
	a = new int[n];
	cout << "Enter the element of array in unordered form : " << n << endl;
	for(int i=0; i<n; i++){
		cout << "element : " << i+1 << endl;
		cin >> a[i];
	}
	cout << " Element are \n[ ";
	for(int i=0; i<n; i++){
		cout << " ";
		cout << a[i];
	}
	cout << " ]";
	cout << "RADIX SORT \n";
	radixsort(a,n);
	//BucketSort(a,n);
	cout << "After Sorting array element is : \n [ ";	
	for(int i=0; i<n; i++){
		cout << " ";
		cout << a[i];
	}	
	cout << " ]";
	return 0;
}
	









 	
