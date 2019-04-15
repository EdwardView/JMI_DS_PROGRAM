#include<iostream>
using namespace std;
void shellSort(int *a,int n){
	int gap = n/2;
	while(gap>=1){
		for(int i=gap; i<n; i++){
			int x = a[i];
			int j=i;
			while(j>=gap  and a[j-gap] > x){
				a[j] = a[j-gap];
				 j = j-gap;
			}
			a[j] = x;
		}
	gap = gap/2;
	}
}
//int main(){
//	int a[] = {5,1,2,4,3};
//	cout << "Before sorting\n";
//	for(int i=0; i<5; i++){
//		cout << i+1 << " element : " << a[i] << endl; 
//	}
//	shellSort(a,5);
//	cout << "After sorting\n";
//	for(int i=0; i<5; i++){
//		cout << i+1 << " element : " << a[i] << endl; 
//	}
//	return 0;
//}
	
