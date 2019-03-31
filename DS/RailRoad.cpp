// Rail Road Arrangement problem.

#include<iostream>
#include"QUEUE.cpp"
using namespace std;
bool RailRoad_Arrangement(int *inputorder,int n,int k){
		queue track[k];
		int nextcartoOutput = 1;
		for(int i = n-1; i>=0; i--){
			if(inputorder[i] == nextcartoOutput){
				cout << "Move car " << inputorder[i] << " from input track to output track\n";
				nextcartoOutput++;
				for(int j=0; j<k-1; j++){
					while(track[j].isEmpty() == false and track[j].getfront() == nextcartoOutput){
						cout << "Move Car " << track[j].delete_in_Q() << " from holding track " << j << " to output track.\n";
						nextcartoOutput++;
						j=0;
					}
				}
			}else{
				int c = inputorder[i];
				int besttrack = -1,bestlast=0;
				for(int j=0; j<k-1; j++){
					if(track[j].isEmpty() == false){
						int lastcar = track[j].getrear();
						if(c > lastcar and lastcar > bestlast){
							bestlast = lastcar;
							besttrack = j;
						}
					}else{
							if(besttrack == -1)
								besttrack = j;
						}
					}
					if(besttrack == -1)
						return false;
					track[besttrack].insert(c);
					cout << "Move car " << c << " to input track to holding track " << besttrack<<endl;
				}
			}
			return true;
}
	
int main(){
	
	int ary[9] = {5,8,1,7,4,2,10,6,3};
	
	if(RailRoad_Arrangement(ary,9,8))
		cout << "\n\nARRANGEMENT IS SUCCESFULLY DONE";
	else
		cout << "ARRANAGEMENT IS NOT SUCCESFULLY DONE.\n";
	return 0;
	
}

