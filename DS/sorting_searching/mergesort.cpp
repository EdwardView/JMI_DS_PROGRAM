#include<iostream>
using namespace std;
void mergesort(int *a,int m,int *b,int n){
	int c[m+n];
	int k=0,j=0,i=0;  // i -> a array , j -> b array , k -> c array
	while(i<m and j<n){   // each element of array a and b comnpare to each other and tranfer to c array 
		if(a[i] < b[j]){
			c[k] = a[i];
			i++;
		}else{
			c[k] = b[j];
			j++;
		}
		k++;
	}
	while(i<m){ // array a element is not completly compare 
		c[k] = a[i];
		i++;
		k++;
	}
	while(j<n){ // array b element is not completly compare
		c[k] = b[j];
		j++;
		k++;
	}
} // merge sort close

void merge(int *a,int low,int mid,int high){
	int c[high-low+1],k=0,i=low,j=mid;
	while(i<=mid and j<= high){
		if(a[i] < a[j]){
			c[k] = a[i];
			i++;
		}else{
			c[k] = a[j];
			j++;
		}
		k++;		
	}
	while(i<=mid){
		c[k] = a[i];
		i++;
		k++;
	}
	while(j<=high){
		c[k] = a[j];
		j++;
		k++;
	}
	for(k=0; k<(high-low); k++){
		a[low+k] = c[k]; 
	}
}
void MergeSort(int *a,int low,int high){
	if(low < high){
		int mid = (low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

int main(){
	int a[] = {5,1,2,4,3};
	cout << "Before sorting\n";
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	MergeSort(a,0,5);
	cout << "After sorting " << endl;
	for(int i=0; i<5; i++){
		cout << i+1 << " element : " << a[i] << endl; 
	}
	return 0;
}

