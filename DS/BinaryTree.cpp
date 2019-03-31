#include<iostream>
#include<math.h>
#include"QUEUE.cpp"
int flag;
int mypower(int n,int p){
	int powe = 1;
	for(int i=1; i<=p; i++){
		powe *= n;
	}
	return powe;
}

using namespace std;
class BTArray{
	char *a;
	int h;
	public :
		BTArray();
		void built(int);
		void inorderTraversal(int);
		void preorderTraversal(int);
		void postorderTraversal(int);
		void levelorderTraversal();
		bool SearchKey(int,char);
		void insertNode(char,char);
		void deleteNode(char);
		void display();
};

BTArray :: BTArray(){
	cout << "Enter the height of Binary Tree :\n";
	cin >> h;
	a = new char[mypower(2,h)-1];
	for(int i=0; i<mypower(2,h)-1; i++)
        a[i] = '\0';
}
void BTArray :: display(){
	for(int i=0; i<mypower(2,h)-1; i++){
		if(a[i] == '\0')
			continue;
		else
			cout << a[i] << "\t";

	}
}
		// Creating Binary Tree.
void BTArray :: built(int i){

	if(i == 0)
		cout << "Enter the Root Node :";
	else if(i%2 == 1)
		cout << "Enter the Left child of the Node ' " << a[(i-1)/2] << " '  : ";
	else
		cout << "Enter the Right child of the node ' " << a[(i-1)/2] <<" ' : ";

	cin >> a[i];

	cout << "Does  " << a[i] << " has Left child Node(y/n) : ";
	char ans;
	cin >> ans;

	if(ans == 'y' and 2*(i+1)-1 < (mypower(2,h)-1))
		built(2*(i+1)-1);

	cout << "Does  " << a[i] << " has Right child Node(y/n) : ";
	cin >> ans;

	if(ans == 'y' and 2*(i+1) < (mypower(2,h)-1))
		built(2*(i+1));
}

	// TRAVERSAL INORDER (LEFT -- ROOT -- RIGHT )

void BTArray :: inorderTraversal(int i){
	if(2*(i+1)-1 < (mypower(2,h)-1) and a[2*(i+1)-1] != '\0')   // LEFT traversal
		inorderTraversal(2*(i+1)-1);
	if(a[i] != '\0')  // ROOT Traversal
		cout << a[i] << "\t";
	if(2*(i+1) < (mypower(2,h)-1) and a[2*(i+1)] != '\0') // Right Traversal
		inorderTraversal(2*(i+1));
}

	// Traversal PreOreder  (ROOT -- LEFT -- RIGHT)
void BTArray :: preorderTraversal(int i){
		if(a[i] != '\0')  // ROOT Traversal
			cout << a[i] << "\t";
		if(2*(i+1)-1 < (mypower(2,h)-1) and a[2*(i+1)-1] != '\0') // LEFT Traversal
			preorderTraversal(2*(i+1)-1);
		if(2*(i+1) < (mypower(2,h)-1) and a[2*(i+1)] != '\0') // RIGHT Traversal
			preorderTraversal(2*(i+1));

}

//		Traversal PostOrder (LEFT -- RIGHT -- ROOT)
void BTArray :: postorderTraversal(int i){
		if(2*(i+1)-1 < (mypower(2,h)-1) and a[2*(i+1)-1] != '\0') // LEFT Traversal
			postorderTraversal(2*(i+1)-1);
		if(2*(i+1) < (mypower(2,h)-1) and a[2*(i+1)] != '\0') // RIGHT Traversal
			postorderTraversal(2*(i+1));
		if(a[i] != '\0')  // ROOT Traversal
			cout << a[i] << "\t";

}

	// Traversal LevelOrder (Read at each Level from Left - Right)
void  BTArray :: levelorderTraversal(){
	if(a[0] == '\0')
		return ;
	static queue Q;
	Q.insert(0);
	while(Q.isEmpty() == false){
		int i = Q.delete_in_Q();
		cout << " " << a[i] << "\t";
		if(2*(i+1)-1 < mypower(2,h)-1 and a[2*(i+1)-1] != '\0'){
			Q.insert(2*(i+1)-1);
		}
		if(2*(i+1) < mypower(2,h)-1 and a[2*(i+1)] != '\0'){
			Q.insert(2*(i+1));
		}
	}
}
	// Search in the Binary tree
bool BTArray :: SearchKey(int i,char key){
		bool rs1=0,rs2=0;
	if(a[0] == '\0'){
		cout << "Tree is Empty.";
		return false;
	}
	if(a[i] == '\0')
		return false;
	if(a[i] == key){  // if Root value is key.
		flag = i;
		return true;
	}
	if((2*(i+1)-1) < (mypower(2,h)-1) and a[2*(i+1)-1] != '\0') // check Left subtree
    	 rs1 = SearchKey(2*(i+1)-1,key);
	if((2*(i+1)) < (mypower(2,h)-1) and a[2*(i+1)] != '\0')	 // check Right subTree
         rs2 =  SearchKey(2*(i+1),key);
	return rs1 || rs2;
}

   // Insertion in the Tree only at Leaf Node
 void BTArray :: insertNode(char key,char item){
 	int i = SearchKey(0,key);
 	if(i == 0){
 		cout << "Key is NOT found so can't insert item.\n";
 		return;
	 }
	 else	
	 	i = flag;
	 if(2*(i+1)>mypower(2,h)-1){
	 	cout << "There is No Space on  the Tree.\n";
	 	return ;
	 }
	 if(a[2*(i+1)-1] != '\0' and a[2*(i+1)] != '\0'){
	 		cout << "Insertion OPertation as Key has Two childerns ";
	 		return;
	 }
	 else if(a[2*(i+1)-1] == '\0' and a[2*(i+1)] == '\0'){
	 	cout << "Do you want new item as Left child(y/n):";
	 	char ans; cin >> ans;
	 	if(ans == 'y')
	 		a[2*(i+1)-1] = item;
	 	else
	 		a[2*(i+1)] = item;
	 }
	 else if(a[2*(i+1)-1] == '\0')
	 	a[2*(i+1)-1] = item;
	 else
		a[2*(i+1)] = item;
 }

void BTArray :: deleteNode(char key){
	int i = SearchKey(0,key);
	if(i == 0){
		cout << "key Does't Exist.\n";
		return;
	}
	else
		i = flag;
	if(2*(i+1)-1 < mypower(2,h)-1 and (a[2*(i+1)-1] == '\0' or a[2*(i+1)] == '\0')){
			cout << "Its not a Leaf Node\n";
			return;
	}
	else
		a[i] = '\0';
}

int main(){
	BTArray B1;
	B1.built(0);
    cout << "Queue : \n " ;
	B1.display();
	cout << "\nInorderTraveral : ";
	B1.inorderTraversal(0);
	cout << "\npreorderTraveral : ";
	B1.preorderTraversal(0);
	cout << "\npostorderTraveral : ";
	B1.postorderTraversal(0);
	// SEARCHING KEY IN THE TREE
	while(1){
	cout << "Enter the key which is search in  Binary tree : \n";
	char key1;
	cin >>
	key1;
	if(B1.SearchKey(0,key1))
		cout << key1 << " is found.\n\n";
	else
		cout <<  key1 << " is not Found.\n";
    cout << "To search Continue Press 1 else press any key : \n";
    int ch;
    cin >> ch;
    if(ch != 1)
        break;
	}
		// DELETION OF KEY ON TJE BINARY TREE.
		while(1){
		cout << "Enter the key which is delete in  Binary tree : \n";
		char key1;
		cin >>
		key1;
		B1.deleteNode(key1);
		cout << "To DELETION Continue Press 1 else press any key : \n";
	    int ch;
	    cin >> ch;
	    if(ch != 1)
	        break;
		} // End Deletion.
	    cout << "After Deletion BT in Queue : \n " ;
		B1.display();
	       // INSERTION OF KEY IN THE BINARY TREE//
	    while(1){
		cout << "Enter the key in which  item is insert in Binary tree and Item which is insert in it. : \n";
		char key1,item1;
		cin >>	key1 >> item1;
	    B1.insertNode(key1,item1);
	    cout << "To Insertion Continue Press 1 else press any key : \n";
	    int ch;
	    cin >> ch;
	    if(ch != 1)
	        break;
		} // end Insertion
	    cout << "Queue : \n " ;
		B1.display();
	
		B1.levelorderTraversal();

	return 0;
}
