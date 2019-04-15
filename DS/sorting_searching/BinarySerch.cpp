#include<iostream>
//#include"QuickSort.cpp"
#include"shellSort.cpp"
using namespace std;

int RBinarySearch(int *a,int low,int high,int key){
	if(low<=high){
		int mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
		if(a[mid] > key)
			return (RBinarySearch(a,low,mid-1,key));
		else
			return (RBinarySearch(a,mid+1,high,key));
	}else
		return -1;
}

int BinarySearch(int *a,int low,int high,int key){
	int mid;
	while(low <= high){
		mid = (low+high)/2;
		if(a[mid] == key)
			return mid;
		if(a[mid] > key)
			high = mid-1;
		else
			low = mid+1;
	}
		return -1;
}
int main(){
	int a[] = {5,1,2,4,3};
	cout << "Before sorting\n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	//QuickSort(a,0,5);
	shellSort(a,5);
	cout << "After sorting\n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	
//	int n = RBinarySearch(a,0,5,3);
	int n = BinarySearch(a,0,5,3);

	if(n == -1)
		cout << "Key not found.\n";
	else
		cout << "Key found at " << n+1 << "position.\n";
	return 0;
}
