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
string Infix_Postfix(string I){
    I = I + ')';
    stack s(I.length()*I.length());
    s.push('(');
    string p;
    char x,y; int i=0;
    while(I[i] != '\0'){
        char x = I[i];
        i++;
        if(x == '(')
            s.push(x);
        else if(x == ')'){
            y = s.pop();
        while(y != '('){
               p = p + y;
               y = s.pop();
           }
        }
        else if(s.isoperator(x)){
            y = s.pop();
            while(s.isoperator(y) and s.precedence(y) >= s.precedence(x)){
            		p = p + y;
            		y = s.pop();
            }
            s.push(y);
            s.push(x);
        }
        else{
             p += x;
            //cout << p;
        }
   }
    return p;
}
int main(){
    cout << "Enter the Infix Expression : \n";
    string I;
    getline(cin,I);
    cout << I << endl;
    cout << I+I;
    string str = Infix_Postfix(I);
    cout << "Post Fix : " << str << endl;
    return 0;
}
