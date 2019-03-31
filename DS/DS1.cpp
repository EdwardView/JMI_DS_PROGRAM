#include<iostream>
using namespace std;
/*class arryException{
	char *str;
	public :
	arryException(char x[])
	{
		s = new char[strlen(x)+1];
		strcpy(str,x);
	}
	friend ostream &operator<< (ostream &abc,arryException a)
	{
		abc << a.str;
	}
};*/	
class ARRAY
{
	int *ary,length,size;
	public :
		ARRAY();
		bool isempty();
		int SIZE();
		void insert(int,int);
		void display();
		int deleteE(int);
		void deleteALl();
		void delete_duplicate();
};
ARRAY :: ARRAY()
{
	cout << "Enter the size of array : " << endl;
	cin >> size;
	ary = new int[size*(size+1)/2];
//	cout <<" the " << size << " Array element : \n" << endl;
	for(int i=0,k=0; i<size*(size+1)/2 && k<size; k++)
	{
		for(int j=0; j<=k; j++,i++)
			ary[i] = k+1;
	}	
}
void ARRAY :: display()
{
	cout << "ARRAY ELEMENT :\n";
	for(int i=0; i<size*(size+1)/2; i++)
		cout << ary[i] << " ";
}
/*int ARRAY :: SIZE ()
{
	int i=0,count=0;
	while(ary[i] != NULL)
	{
		count++;
		i++;
	}
	//cout << *(&ary + 1) - ary <<endl;
	//cout << sizeof(ary)/sizeof(int) << endl;
	//return sizeof(ary)/sizeof(ary[0]);
	return count;
}*/
	
int main()
{
	ARRAY A;

	A.display();
//	cout << "\n" << "SIZE OF ARRAY : \t" << A.SIZE() << endl;
	return 0;
}

	


