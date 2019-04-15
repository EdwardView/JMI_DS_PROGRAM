#include<iostream>
using namespace std;
int partition(int *a,int low,int high){
	int pivotElement = a[low];
	int j = low;
	for(int i=low+1; i<=high; i++){
		if(a[i] < pivotElement){
			j++;
			if(i != j){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	int pivotpoint = j;
	if(j != low){
		int temp = a[j];
		a[j] = a[low];
		a[low] = temp;
	}
}
void QuickSort(int *a,int low,int high){
	if(low < high){
		int p = partition(a,low,high);
		QuickSort(a,low,p-1);
		QuickSort(a,p+1,high);
	}
}
int main(){
	int a[] = {5,1,2,4,3};
	cout << "Before sorting\n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	QuickSort(a,0,5);
	cout << "After sorting\n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	return 0;
}
