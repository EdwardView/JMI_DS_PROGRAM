#include<iostream>
using namespace std;
class HashTable{
	int *a,h,n,m;
	public:
		HashTable(int n){
			a = new int[n];
			for(int i=0; i<n; i++)
				a[i] = -1;
			this->n = n;
			int temp = n,flag = 1;
			do{
				temp ++;
				for(int i=2; i<temp/2; i++){
					if(temp % i == 0){
						flag = 0;
						break;
					}
				}
			}while(flag == 1);
			h = temp;
			do{
				temp --;
				for(int i=2; i<temp/2; i++){
					if(temp % i == 0){
						flag = 0;
						break;
					}
				}
			}while(flag == 1);
			m = temp;
		}
		void insert(int key);
		int search(int key);
		void del(int key);
		void display();
};
void HashTable::insert(int key){
	int index=(key%h);
	do{
		if(a[index] == -1){
			a[index] = key;
			return;
		}else if(a[index] == key){
			cout << "Key is already present in the hash table.\n";
			return ;
		}else{
			//index = (index+1)%h;
			index = (index+m)%h;
		}
	}while(index != (key%h));
	cout << "Hash table is full.\n";
}
int HashTable::search(int key){
	int index = key%h;
	do{
		if(a[index] == -1)
			return -1;
		else if(a[index] == key)
				return index;
		else 
			index = (index+1)%h;
	}while(index != (key%h));
	return -1;
}
void HashTable::del(int key){
	int i = search(key);
	if(a[i] == -1){
		cout << "Key des't exist.\n";
		return;
	}
	int j = (i+1)%h;
	int k=i;
	while(j != k && a[i] != -1){
		if(a[j]%h <= i)
			a[i] = a[j];
		j = (j+1)%h;
	}
	a[i] = -1;
}
void HashTable :: display(){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main(){
	HashTable h(5);
	int n;
	for(int i=0; i<5; i++){
		cout << "Entre the value to insert into hash table : "; 
		cin >> n;
		h.insert(n);
	}
	cout << "HashTable\n";
	h.display();
	cout << "Entre the value to delete into hash table : "; 
	cin >> n;
	cout << "After Deletion:\n";
	h.display();
	
	return 0;	
}

