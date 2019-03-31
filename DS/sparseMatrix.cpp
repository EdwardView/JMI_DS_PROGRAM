#include<iostream>
using namespace std;
class SparseMatrix{
    int *row,col*,*value[],NONZ,rows,cols;
    public :
            SparseMatrix(){
                cout << "Enter the total number of no.zero element in SparseMatrix.\n";
                cin >> NONZ;
                cout << "Enter the number of row present in SparseMatrix :\n";
                cin >> rows;
                cout << "Enter the number of column present in SparseMatrix : \n";
                cin >> cols;
                row = new int[NONZ];
                col = new int[NONZ];
                value = new int[NONZ];
            }
            void read ();
            void print();
            SparseMatrix ADD();
};
void SparseMatrix :: read (){
    cout << "Enter the information of non Zero Element : \n";
    for(int i=0; i<NONZ; i++){
        cout << "Enter the Row and Column where element is stored :\n";
        cin >> row[i];cout << ":"; cin >> col[i];
        cout << "Enter the value : \n" << value[i];
    }
}
void SparseMatrix :: print(){
    cout << "\t\tSparse Matrix\n";
    
        for(int i=0; i<rows; i++){
            int k=0,found=0;
            for(int j=0; j<cols; j++){
                        while(k<NONZ){
                            if(row[k] == i and col[k] == j){
                                found++;
                                break;
                            }
                          	
							  k++;

                        }
            }


    }
}
