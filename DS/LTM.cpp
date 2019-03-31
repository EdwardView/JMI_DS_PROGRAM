#include<iostream>
using namespace std;
int MAP_ROW(int i,int j){
        return (i*(i+1))/2 + j;
}
int MAP_COL(int i,int j,int n){
        return (i - (j*(j+1))/2 + n*j);
}
template <class T>
class LTM{
    T *matrix;
    int order;
    public :
        LTM(int);
        void read();
        void print();
        void det();
        LTM inverse();
        LTM MUL(LTM);
        LTM add(LTM);
        LTM sub(LTM);

};
template <class T>
LTM <T> :: LTM(int k){
    matrix = new T[k*(k+1) / 2];
    order = k;
}
template <class T>
void LTM<T> :: read (){
    cout << "Enter the Element of LTM of order ("<<order << "*" << order << ") and total Element is " << order*(order+1)/2 << endl;
    for(int i=0; i<order*(order+1)/2; i++){
        cout << "\nEnter Element : ";
        cin >> matrix[i];
    }
}
template <class T>
void LTM<T> :: print(){
    cout << "L T M element : \n ";
    for(int i=0; i<order; i++){
        for(int j=0; j<order; j++){
            if(i>=j)
                cout <<matrix[MAP_ROW(i,j)] <<"\t";
            else
                cout << "0\t";
        }
        cout << endl;
    }
}
int main(){
    int n;
    cout<<"Enter the order of matrix : \n" ;
    cin >> n;
    LTM <float> L1(n);
    L1.read();
    L1.print();

    return 0;
}
