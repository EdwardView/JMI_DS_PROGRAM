#include<iostream>
#include<string.h>
using namespace std;
class stack
{
    char *a;
    int length,tos;
    public :
        stack(int n){
            length = n;
            a = new char [n];
            tos = -1;
            }
        bool isEmpty();
        bool isoperator(char x);
        void push (char x);
        char  pop ();
        int precedence(char);
};
bool stack::isEmpty(){
	if(tos==-1)
		return true;
	else
		return false;
}
void stack :: push(char x){
    a[++tos] = x;
}
char  stack :: pop(){
        return a[tos--];
}
bool stack :: isoperator(char x){
    if(x == '+' or x == '-' or x == '*' or x == '/' or x == '%')
        return true;
    else
        return false;
}
int stack :: precedence(char ch){
    switch(ch){
        case '+':return 3;
        case '-':return 3;
        case '*':return 4;
        case '/':return 4;
        case '%':return 4;
    }
}
string infix_prefix(string str){
	char ch;
	str = str + ');
	stack s(str.length());
	s.push('(');
	for(int i=str.length()-1; i>=0; i--){
		if()
		
	}
		
	
	
	
	
}
