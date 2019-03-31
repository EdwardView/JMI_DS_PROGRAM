
#include<iostream>
#include<math.h>
using namespace std;
class point
{
	public:
    int row,col;
    public :
    	point(int r=0,int c=0){
            row = r;
            col = c;
        }
};
class stack{
	point *p;
	int length,tos;
	public:
		stack(int m)
		{
			length = m;
			p = new point[m];
			tos=-1;
		}
		bool isEmpty();
		int getSize();
		void push(point x);
		point pop();
		void display();
};
void stack ::push(point x)
{
	p[++tos]=x;
}
point stack :: pop()
{
	return p[tos--];
}
void  stack :: display()
{
	cout<<"[";
	for(int i=0; i<=tos; i++)
	{
		cout<< "(" <<p[i].row<<", " << p[i].col << ") -> ";
	}
	cout<<"\b\b]";
}
bool getpath(int Maze[3][3],int m,int n){
    int row = 0, col = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << Maze[i][j] << "\t";
        }
        cout << '\n';
    }
    Maze[row][col] = 1;
    stack s(m*n - 1);
    while(row != m-1 or col != n-1){
        if(col < n-1 and Maze[row][col+1] == 0){// right Checking block is not contain Huddle.
            point p1(row,col);
			s.push(p1);
            col++;
            Maze[row][col] = 1;
        }
        else if(row < m-1 and Maze[row+1][col] == 0){ // Down checking block is not contain Huddle
            point p1(row,col);
			s.push(p1);
            row++;
            Maze[row][col] = 1;
        }
        else if(col > 0 and Maze[row][col-1] == 0){ // Left checking block is not contain Huddle
            point p1(row,col);
			s.push(p1);
            row++;
            Maze[row][col] = 1;
        }
        else if(row > 0 and Maze[row-1][col] == 0){ // TOp checking block is not contain huddle
            point p1(row,col);
			s.push(p1);
            row--;
            Maze[row][col] = 1;
        }
        else{
            if(s.isEmpty() == true) return false;
            else{
                point p = s.pop();
                row = p.row;
                col = p.col;
            }
        }
   }
    point p = s.pop();
    s.push(p);
    s.display();
	return true;
}
int main(){
    int n,m;
    cout << "Enter the ROw And Column of Maze.\n";
    cin >> m >> n;
    int ptr[3][3];
    cout << "Press 1 for block contain Huddle(row,colunm) for RAT and 0 for free area at which RAT can travel \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << "PTR[" << i << "]" << "[" << j << "]\t->";
            cin >> ptr[i][j];
        }
    }
    if(getpath(ptr,m,n))
        cout << "path found.\n";
    else
        cout << "Path not Found";

}

