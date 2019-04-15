#include<iostream>
using namespace std;
void selection_sort(int *ary,int n){
	int minindex ;
	for(int i=0; i<n; i++){
		minindex = i;
		for(int j=i+1; j<n;j++){
			if(ary[j] < ary[minindex])
				minindex = j;
		}
		if(i != minindex){
			int temp = ary[i];
			ary[i] = ary[minindex];
			ary[minindex] = temp;
		}
	}
}	
void bubble_sort(int *ary,int n){
	bool issort = true;
	for(int i=0; i<n; i++){
		issort = true;
		for(int j=0; j<n-i-1;j++){
			if(ary[j] > ary[j+1]){
				int temp = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = temp;
				issort = false;
			}
		}
		if(issort == true)
			break;
  	}
}
void insertion_sort(int *a,int n){
	for(int i=1; i<n; i++){
		int x = a[i];
		int j=i-1;
		while(j>=0 && a[j] > x){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = x;
	}
}
int main(){
	int a[] = {5,1,2,4,3};
	cout << "Before sorting\n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
//	selection_sort(a,5);
//	cout << "After sorting \n";
//	for(int i=0; i<5; i++){
//		cout << i+1 << " element : " << a[i] << endl; 
//	}
//	bubble_sort(a,5);
//	cout << "After sorting \n";
//	for(int i=0; i<5; i++){
//		cout << i+1 << " element : " << a[i] << endl; 
//	}
	insertion_sort(a,5);
	cout << "After sorting \n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	return 0;
}
