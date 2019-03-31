#include<iostream>
using namespace std;
class NODE{
	public:
		int data;
		NODE *left,*right;
		NODE(){
			left = NULL;
			right = NULL;
		}
};
class BTLinklist{
	NODE *root;
	public :
		BTLinklist(){}
		void built(NODE * curr,NODE *Parent);
		void inorderTraversal(NODE *);
		void preorderTraversal(NODE *);
		void postorderTraversal(NODE *);
//		void levelorderTraversal();
		bool SearchKey(NODE *,int);
		void insertNode(int,int);
		void deleteNode(int);
		void display();
		int getheight(NODE*);
		NODE * getroot();
};
void BTLinklist :: built(NODE *curr,NODE *P){
	char ans;
	 if(curr == NULL){
	 	root = curr = new NODE;
	 	cout << "Enter the Root Node : \n";
	 }else if(curr == P->left){
	 	cout << "Enter the Left Child of " << P->data << " ";
	 }else{
	 	cout << "Enter the Right Child of " << P->data << " ";
	 }
	 cin >> curr->data;
	 cout << "Does " << curr->data << " have left child(Y/N)";
	 cin >> ans;
	 if(ans == 'Y' or ans == 'y'){
	 	curr->left = new NODE;
	 	built(curr->left,curr);
	 }
	 cout << "Does " << curr->data << " have right child(Y/N)";
	 cin >> ans;
	 if(ans == 'Y' or ans == 'y'){
	 	curr->right = new NODE;
	 	built(curr->right,curr);
	 }
} 
void BTLinklist :: inorderTraversal(NODE * r){ // Inorder Traversal -> LEFT - ROOT - RIGHT 
	if(r->left != NULL)
		inorderTraversal(r->left);
	if(r != NULL)
		cout << "\nDATA => " << r->data;
	if(r->right != NULL)
		inorderTraversal(r->right); 
}
NODE* BTLinklist :: getroot(){
	return root;
}
void BTLinklist :: preorderTraversal(NODE * r){ // PREODER TRAVERSAL -> LEFT - RIGHT - ROOT
	if(r != NULL)
		cout << "\nDATA => " << r->data;
	if(r->left != NULL)
		inorderTraversal(r->left);
	if(r->right != NULL)
		inorderTraversal(r->right); 
}
void BTLinklist :: postorderTraversal(NODE * r){ // POST ORDER TRAVERSAL -> ROOT - LEFT - RIGHT
	if(r->left != NULL)
		inorderTraversal(r->left);
	if(r->right != NULL)
		inorderTraversal(r->right); 
	if(r != NULL)
		cout << "\nDATA => " << r->data;
}
//	// Traversal LevelOrder (Read at each Level from Left - Right)
//void  BTLinklist :: levelorderTraversal(NODE * r){
//	if(root == '\0')
//		return ;
//	static queue Q;
//	Q.insert(r->data);
//	while(Q.isEmpty() == false){
//		char data = Q.delete_in_Q();
//		cout << " " << data << "\t";
//		if(r->left != NULL){
//			Q.insert(temp->left->data);
//		}
//		if(r->right != NULL){
//			Q.insert(r->right->data);
//		}
//	}
//}
int BTLinklist :: getheight(NODE *r){
	if(r == NULL) return 0;
	if(getheight(r->left) > getheight(r->right))
		return getheight(r->left)+1;
	else
		return getheight(r->right)+1;
}
	// Search in the Binary tree
bool BTLinklist :: SearchKey(NODE *r,int key){
	bool rs1=0,rs2=0;
//	if(root == NULL){
//		cout << "Tree is Empty.";
//		return false;
//	}
//	if(r == NULL)
//		return false;
	if(r->data == key){  // if Root value is key.
		return true;
	}
	if(r->left != NULL) // check Left subtree
    	 rs1 = SearchKey(r->left,key);
	if(r->right != NULL)	 // check Right subTree
         rs2 =  SearchKey(r->right,key);
	return rs1 || rs2;
}
int main(){
	BTLinklist BT;
	BT.built(NULL,NULL);
	BT.inorderTraversal(BT.getroot()); // Inorder Traversal 
//	BT.preorderTraversal(BT.getroot()); // PreOrder Traversal
//	BT.postorderTraversal(BT.getroot()); // Post Order Traversal
//	BT.levelorderTraversal(BT.getroot()); // Level Order Traversal1
	cout << "\n\n" << BT.getheight(BT.getroot());
	if(BT.SearchKey(BT.getroot(),3))
		cout << "Key is found.\n";
	else
		cout << "Key is not found.\n";
	return 0;
}
