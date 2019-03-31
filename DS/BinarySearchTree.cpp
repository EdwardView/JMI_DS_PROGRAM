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
class BST{
	NODE * root;
	public:
		BST(){ root = NULL;}
		bool insertNode(int);
		void inorderTraversal(NODE *);
		NODE* getroot();
		int del(int);
};
void BST :: inorderTraversal(NODE * r){ // Inorder Traversal -> LEFT - ROOT - RIGHT 
	if(r->left != NULL)
		inorderTraversal(r->left);
	if(r != NULL)
		cout << "\nDATA => " << r->data;
	if(r->right != NULL)
		inorderTraversal(r->right); 
}
bool BST :: insertNode(int x){
	if(root == NULL){
		root = new NODE;
		root->data = x;
		root->left = root->right = NULL;
	}else{
		NODE *p = NULL;
		NODE * curr = root;
		while(curr != NULL){
			if(x < curr->data){
				p = curr;
				curr = curr->left;
			}else if(x == curr->data){
					cout << "X is alrready exist.\n";
					return 0;				
			}else{
				p = curr;
				curr = curr->right;
			}
		}// while close
		NODE * nNode = new NODE;
		nNode->data = x;
		if(x < p->data)
			p->left = nNode;
		else
			p->right = nNode;
	}
	return 1;
}
NODE* BST :: getroot(){
	return root;
}
int BST :: del(int x){
	if(root == NULL){
		cout << "BST is empty.\n";
		exit(1);
	}
	NODE * r,*par;
	int temp;
	NODE * inorderpred ,*pofinorderpred; 
	r = root;	par = NULL;
	while(r != NULL and r->data != x){ // reach which node we will delete.
		if(x > r->data){
			par = r;
			r = r->right;
		}else{
			par = r;
			r = r->left;
		}
	}
	if(par == NULL and r->left == NULL and r->right == NULL){ // parent node have no child node 
	    temp = r->data;
		root = NULL;
		delete(r);
	}else{
		if(par != NULL and r->left == NULL and r->right == NULL){ // parent node have left child node 
 			int temp = r->data;
			if(par->left == r)
				par->left = NULL;
			else
				par->right = NULL;
		}else if(par != NULL and (r->left == NULL and r->right != NULL ) or (r->left != NULL and r->right == NULL)){
			if(par->left == r){
				if(r->left != NULL)
					par->left = r->right;
				else
					par->right = r->left;
			}else{
				if(r->left != NULL)
					par ->right = r->left;
				else
					par ->left = r->right;
			}
		}else{
			inorderpred = r->left;
			pofinorderpred = r;
			while(inorderpred->right != NULL){
				pofinorderpred = inorderpred;
				inorderpred = pofinorderpred->right; 
			}
			temp = r->data;
			r->data = inorderpred->data;
			if(inorderpred == pofinorderpred -> left){
			pofinorderpred -> left = inorderpred ->left;
			delete(inorderpred ->left);
			}else{
				pofinorderpred->right = inorderpred->left;
				delete(inorderpred);
			}
		}
	}
	return temp;
}
int main(){
	BST BT;
	int n;
	for(int i=0; i<15; i++){
		cin >> n;
		if(BT.insertNode(n))
			continue;
		else{
			cin >> n;
			BT.insertNode(n);			
		}
	}
	BT.inorderTraversal(BT.getroot());
	cout << "\n\n" << BT.del(4) << endl;
	cout << "After Deletiom .\n";
	BT.inorderTraversal(BT.getroot());
	
	return 0;
}
