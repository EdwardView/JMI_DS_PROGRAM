#include<iostream>
using namespace std;

class point{
	int x,y;
	public :
		point();
		friend int tocompare(point &,point &);
		void display();
};
point :: point()
{
    cout << "Enter the points(x,y)\n";
    cin >> x >> y;
}
void point :: display(){
cout << "Point (x,y) = ( " << x << "," << y << ")\n";
}
int tocompare(point &p1,point &p2){
	return ((p2.x - 0) * (p1.y - 0) - (p1.x - 0) * (p2.y - 0));
}
int main(){
	point p1,p2;
	p1.display();
	p2.display();
    int p = tocompare(p1,p2);
	if(p == 0)
        cout << "Points are in same plane.\n";
    else if(p>0)
        cout <<"p1 polar angle is greater than p2.\n";
    else
        cout << "P2 polar angle is greater than p1.\n";
    return 0;
}
