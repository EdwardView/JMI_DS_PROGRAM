#include<iostream>
//#include"QuickSort.cpp"
#include"shellSort.cpp"
using namespace std;

int TernarySearch(int *a,int low,int high,int key){
	int mid1,mid2;
	while(low <= high){
		mid1 = (low+high)/3;
		mid2 = mid1*2;
		if(a[mid1] == key)
			return mid1;
		else if(a[mid1] > key)
			high = mid1-1;
		else if(a[mid2 == key])
			return mid2;
		else if(a[mid2 > key]){
			low = mid1+1;
			high = mid2-1;
		}else
			low = mid2+1;
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
	int n = TernarySearch(a,0,5,3);

	if(n == -1)
		cout << "Key not found.\n";
	else
		cout << "Key found at " << n+1 << "position.\n";
	return 0;
}
